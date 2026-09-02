#!/usr/bin/env python3
"""
@file gen_tag_header.py

@brief Data-driven C header generator from tag schemas

Copyright (C) Atmosic 2026
"""

import os
import shutil
import subprocess
import datetime
from dataclasses import dataclass, field

__all__ = ["HeaderSection", "HeaderGenerator"]


@dataclass
class HeaderSection:  # pylint: disable=too-many-instance-attributes
    """Describes one section in the generated C header.

    A section produces, in order:
      1. Optional leading C lines  (e.g. comments, enums before the defines)
      2. One or more ``#define NAME 0xNN`` lines  (defines)
      3. Optional pre-struct C lines  (e.g. enums, macros before BF typedefs)
      4. Typedef auto-generated from schema (BF, UNION, struct)
      5. Optional trailing C lines  (e.g. macros or enums after the struct)

    BF fields automatically produce ``_{field_name}_bits_t`` (packed struct)
    and ``{field_name}_t`` (union).  The outer struct member uses that union
    type automatically, e.g. ``flags_t flags;``.

    Attributes:
        schema: List of ``(field_name, format, size_or_dict)`` tuples.
                Supported formats:
                  - B/b/H/h/I/i: scalar types
                  - s: byte array (size = array length)
                  - BF: bitfield dict with optional ``_size`` and bit entries
                  - UNION: union typedef dict with ``_typedef_name`` and options
        struct_name: C typedef struct name, e.g. ``'my_config_t'``.
        defines: Ordered list of ``(define_name, value)`` pairs, e.g.
                 ``[('MY_DEFINE', 0x10)]``.
        leading_lines: C lines emitted before the defines.
        trailing_lines: C lines emitted after the struct.
        field_comments: Dict mapping BF field names to inline C comments,
                        e.g. ``{'encr_mode': '// encr_mode_t'}``.
        pre_struct_lines: C lines emitted after the defines but before the
                          typedef generation and struct.
        field_trailing_lines: Dict mapping BF field names to a list of C lines
                              emitted after that field's union typedef.
        skip_struct: If True, skip auto-generating the struct (use
                     trailing_lines to provide a custom struct definition).
    """

    schema: list[tuple]
    struct_name: str
    defines: list[tuple]
    leading_lines: list[str] = field(default_factory=list)
    trailing_lines: list[str] = field(default_factory=list)
    field_comments: dict[str, str] = field(default_factory=dict)
    pre_struct_lines: list[str] = field(default_factory=list)
    field_trailing_lines: dict[str, list[str]] = field(default_factory=dict)
    skip_struct: bool = False


class HeaderGenerator:  # pylint: disable=too-many-instance-attributes
    """Data-driven C header generator.

    Completely decoupled from any specific tag tool.  The caller builds
    ``TagSection`` objects describing each section of the header, calls
    ``add_section()`` for each, then calls ``generate()`` to write the file.

    Example::

        gen = HeaderGenerator(brief='My tag definitions',
                              output_file='tags.h',
                              output_dir='/path/to/src',
                              source_file=__file__)
        gen.add_section(TagSection(
            defines=[('MY_TAG', 0x10)],
            schema=[('field_a', 'B', None), ('field_b', 's', 4)],
            struct_name='my_tag_t',
        ))
        gen.generate()
    """

    # Mapping from schema format codes to C types
    FORMAT_TO_CTYPE = {
        "B": "uint8_t",
        "b": "int8_t",
        "H": "uint16_t",
        "h": "int16_t",
        "I": "uint32_t",
        "i": "int32_t",
        "s": "uint8_t",  # byte array; size in schema gives array length
    }

    # BF '_size' (bytes) -> C integer type for the bitfield word
    BF_SIZE_TO_CTYPE = {1: "uint8_t", 2: "uint16_t", 4: "uint32_t"}

    def __init__(
        self,
        *,
        brief,
        output_file,
        output_dir,  # pylint: disable=too-many-arguments
        source_file=None,
        includes=None,
        doc_group=None,
        clang_format=None,
    ):
        """
        Args:
            brief: brief string for the doxygen file comment.
            output_file: Output filename, e.g. ``'my_tag_definitions.h'``.
            output_dir: Directory to write the header file into.
            source_file: ``__file__`` of the calling script; shown in the
                         auto-generated warning comment.
            includes: Optional list of include specs emitted after the file
                      header, e.g. ``['<stdint.h>', 'compiler.h']``. Entries
                      already wrapped in ``<>`` or ``""`` are emitted verbatim;
                      bare names are wrapped in double quotes.
            doc_group: Optional dict describing a Doxygen ``@defgroup`` block
                       wrapped around the whole body, with keys ``name`` and
                       optional ``title``/``ingroup``/``brief``.
            clang_format: Optional; when truthy the written header is formatted
                          in place with clang-format. ``True`` uses
                          ``--style=file`` (clang-format discovers the nearest
                          ``.clang-format``); a string is passed verbatim to
                          ``--style=``. A missing binary is reported but does
                          not fail generation. Off by default.
        """
        self.brief = brief
        self.output_file = output_file
        self.output_dir = output_dir
        self.source_file = source_file or "(unknown)"
        self.includes = includes or []
        self.doc_group = doc_group
        self.clang_format = clang_format
        self._sections = []

    def add_section(self, section):
        """Append a TagSection to be emitted when ``generate()`` is called."""
        self._sections.append(section)

    def generate(self):
        """Write the generated header file to ``output_dir/output_file``.

        Returns:
            str: Full path of the written header file.
        """
        os.makedirs(self.output_dir, exist_ok=True)
        header_file = os.path.join(self.output_dir, self.output_file)
        with open(header_file, "w", encoding="utf-8") as f:
            f.write(self._build_content())
        print(f"Successfully generated header: {header_file}")
        if self.clang_format:
            self._run_clang_format(header_file)
        return header_file

    def _run_clang_format(self, header_file):
        """Format ``header_file`` in place with clang-format, if configured.

        ``clang_format`` may be ``True`` (use ``--style=file`` so clang-format
        finds the nearest ``.clang-format``) or a style string passed verbatim
        to ``--style=``. A missing binary or a clang-format error is reported
        but does not fail generation.
        """
        style = self.clang_format if isinstance(self.clang_format, str) else "file"
        binary = shutil.which("clang-format")
        if binary is None:
            print(
                "WARNING: clang-format not found; "
                f"generated header left unformatted: {header_file}"
            )
            return
        try:
            subprocess.run([binary, f"--style={style}", "-i", header_file], check=True)
            print(f"Formatted header with clang-format: {header_file}")
        except subprocess.CalledProcessError as exc:
            print(
                f"WARNING: clang-format failed ({exc}); "
                f"header left as-is: {header_file}"
            )

    def _build_content(self):
        """Build and return the full header file content as a string."""
        lines = self._build_file_header()
        lines.extend(self._build_doc_group_open())
        lines.extend(self._build_includes())
        lines.extend(self._build_cpp_guard_open())
        for section in self._sections:
            lines.extend(self._gen_section(section))
        # Remove trailing empty line from last section before adding close guard
        while lines and lines[-1] == "":
            lines.pop()
        lines.append("")  # Add single empty line before closing guard
        lines.extend(self._build_cpp_guard_close())
        doc_group_close = self._build_doc_group_close()
        if doc_group_close:
            lines.append("")  # Blank line before the closing @} marker
            lines.extend(doc_group_close)
        lines.append("")  # Add final empty line at end of file
        return "\n".join(lines)

    def _build_includes(self):
        """Build #include lines from the configured includes list."""
        if not self.includes:
            return []
        lines = []
        for inc in self.includes:
            if inc.startswith("<") or inc.startswith('"'):
                lines.append(f"#include {inc}")
            else:
                lines.append(f'#include "{inc}"')
        lines.append("")
        return lines

    def _build_doc_group_open(self):
        """Build the opening Doxygen ``@defgroup`` block, if configured."""
        if not self.doc_group:
            return []
        name = self.doc_group["name"]
        lines = ["/**", f" * @defgroup {name} {self.doc_group.get('title', name)}"]
        if self.doc_group.get("ingroup"):
            lines.append(f" * @ingroup {self.doc_group['ingroup']}")
        if self.doc_group.get("brief"):
            lines.append(f" * @brief {self.doc_group['brief']}")
        lines.extend([" * @{", " */", ""])
        return lines

    def _build_doc_group_close(self):
        """Build the closing ``@}`` marker for the Doxygen group, if configured."""
        if not self.doc_group:
            return []
        return [f"/// @}} {self.doc_group['name']}"]

    def _build_file_header(self):
        """Build the standard doxygen file comment block and #pragma once."""
        return [
            "/**",
            " *******************************************************************************",
            " *",
            f" * @file {self.output_file}",
            " *",
            f" * @brief {self.brief}",
            " *",
            f" * Copyright (C) Atmosic {datetime.date.today().year}",
            " *",
            " * SPDX-License-Identifier: LicenseRef-Atmosic",
            " *",
            " *******************************************************************************",
            " */",
            "",
            "#pragma once",
            "",
            "////////////////////////////////////////////",
            f"// Auto-generated from {os.path.basename(self.source_file)}",
            "// WARNING: DO NOT EDIT THIS FILE",
            "////////////////////////////////////////////",
            "",
        ]

    @staticmethod
    def _build_cpp_guard_open():
        """Build opening C++ guard."""
        return [
            "#ifdef __cplusplus",
            'extern "C" {',
            "#endif",
            "",
        ]

    @staticmethod
    def _build_cpp_guard_close():
        """Build closing C++ guard."""
        return [
            "#ifdef __cplusplus",
            "}",
            "#endif",
        ]

    @staticmethod
    def _format_comment_lines(comment):
        """Convert comment string/list to C comment lines.

        Args:
            comment: String (with \\n for newlines) or list of strings

        Returns:
            List of C comment lines (starting with //)
        """
        if not comment:
            return []

        # Handle both string and array formats
        if isinstance(comment, list):
            comment_lines = [line.rstrip("\n") for line in comment]
        else:
            # String format: split by \n
            comment_str = str(comment)
            # Handle JSON escape sequences: replace \\n with actual newline
            comment_str = comment_str.replace("\\n", "\n")
            # Split comment by newlines
            comment_lines = comment_str.split("\n")

        # Convert to C comments, skip empty lines
        return [f"// {line}" for line in comment_lines if line.strip()]

    @staticmethod
    def _format_doxygen_lines(comment):
        """Convert comment string/list to Doxygen ``///`` comment lines."""
        return [
            line.replace("//", "///", 1)
            for line in HeaderGenerator._format_comment_lines(comment)
        ]

    def _gen_section(self, section):
        """Generate all C lines for a single HeaderSection.

        Order: leading_lines -> defines -> pre_struct_lines -> typedef generation
               (BF & UNION) -> struct -> trailing_lines.
        """
        lines = list(section.leading_lines)
        for define_name, tag_id in section.defines:
            lines.append(f"#define {define_name} 0x{tag_id:02x}")
        lines.extend(section.pre_struct_lines)
        for field_info in section.schema:
            if field_info[1] == "BF":
                gen_lines = self._gen_bf_types(
                    field_info[0], field_info[2], section.field_comments
                )
                lines.extend(gen_lines)
                lines.extend(section.field_trailing_lines.get(field_info[0], []))
            elif field_info[1] == "UNION":
                gen_lines = self._gen_union_typedef(field_info[0], field_info[2])
                lines.extend(gen_lines)
                lines.extend(section.field_trailing_lines.get(field_info[0], []))
        if not section.skip_struct:
            lines.extend(self._gen_struct(section.schema, section.struct_name))
        lines.extend(section.trailing_lines)
        lines.append("")
        return lines

    def _gen_bf_types(
        self, field_name, bf_dict, field_comments=None
    ):  # pylint: disable=too-many-locals
        """Generate bits-struct and typedef alias for one BF schema field.

        Naming convention:
            bits struct : ``_{field_name}_bits_t`` or custom from '_bits_typedef_name'
            typedef alias : ``{field_name}_t`` or custom from '_typedef_name'

        Args:
            field_name: Schema field name, e.g. ``'flags'``.
            bf_dict: BF dict with optional keys:
                     - '_size': byte size (1, 2, or 4)
                     - '_typedef_name': custom name for typedef alias
                     - '_bits_typedef_name': custom name for bits struct typedef
                     - bit-field entries like 'encr_mode': (bit_pos, mask)
            field_comments: Optional dict mapping sub-field names to inline C
                            comments, e.g. ``{'encr_mode': '// encr_mode_t'}``.
        """
        field_comments = field_comments or {}
        ctype = self._get_bf_ctype(field_name, bf_dict)
        bits_name, typedef_name = self._get_bf_typedefs(field_name, bf_dict)

        lines = ["typedef struct {"]
        lines.extend(self._gen_bf_field_lines(bf_dict, ctype, field_comments))
        lines.append(f"}} __packed {bits_name};")

        if bits_name != typedef_name:
            lines.append(f"typedef {bits_name} {typedef_name};")

        lines.append("")
        return lines

    def _get_bf_ctype(self, field_name, bf_dict):
        """Get C type for bitfield based on size."""
        size = bf_dict.get("_size", 1)
        if size not in self.BF_SIZE_TO_CTYPE:
            raise ValueError(
                f"Unsupported BF _size: {size} in field '{field_name}'. Must be 1, 2, or 4."
            )
        return self.BF_SIZE_TO_CTYPE[size]

    def _get_bf_typedefs(self, field_name, bf_dict):
        """Get typedef names for bitfield."""
        bits_name = bf_dict.get("_bits_typedef_name", f"_{field_name}_bits_t")
        typedef_name = bf_dict.get("_typedef_name", f"{field_name}_t")
        return bits_name, typedef_name

    def _gen_bf_field_lines(self, bf_dict, ctype, field_comments):
        """Generate all bitfield lines in the struct definition."""
        bf_fields = sorted(
            ((k, v) for k, v in bf_dict.items() if not k.startswith("_")),
            key=lambda x: x[1][0],
        )
        return [
            self._gen_bf_field_line(fname, bf_info, ctype, field_comments)
            for fname, bf_info in bf_fields
        ]

    def _gen_bf_field_line(self, fname, bf_info, ctype, field_comments):
        """Generate one bitfield line in the struct definition.

        Args:
            fname: Bitfield name
            bf_info: 3-tuple (bit_pos, mask, comment)
            ctype: C type for the bitfield storage
            field_comments: Dict of field name to comment string

        Returns:
            String: formatted bitfield line
        """
        # bf_info is a 3-tuple: (bit_pos, mask, comment)
        # comment can be None
        _, mask, bf_comment = bf_info

        # Use comment from bf_info if not already in field_comments
        if fname in field_comments:
            comment = f" {field_comments[fname]}"
        elif bf_comment:
            comment = f" // {bf_comment}"
        else:
            comment = ""

        return f"\t{ctype} {fname}: {mask.bit_length()};{comment}"

    def _gen_union_typedef(self, field_name, union_dict):
        """Generate typedef union with multiple struct options from schema.

        union_dict format:
        {
            '_typedef_name': 'my_union_t',
            'option1_name': [('field1', 'B', None), ...],
            'option2_name': [('field2', 'H', None), ...],
        }
        """
        # Internal union typedefs use _ prefix
        typedef_name = union_dict.get("_typedef_name", f"_{field_name}_t")

        lines = ["typedef union {"]

        for opt_name, opt_schema in union_dict.items():
            if opt_name.startswith("_"):
                continue

            # Generate each option's struct
            lines.append("\tstruct {")
            for opt_field in opt_schema:
                field_str = self._schema_field_to_c(opt_field)
                # Remove leading tab and add extra indentation for nested struct
                lines.append(f"\t\t{field_str.lstrip()}")
            lines.append(f"\t}} {opt_name};")

        lines.extend(
            [
                f"}} __packed {typedef_name};",
                "",
            ]
        )

        return lines

    def _gen_struct(self, schema, struct_name):
        """Generate typedef struct from schema."""
        if not schema:
            raise ValueError(f"struct '{struct_name}' has an empty schema")
        lines = ["typedef struct {"]
        for field_info in schema:
            lines.append(self._schema_field_to_c(field_info))
        lines.append(f"}} __packed {struct_name};")
        return lines

    def _gen_bf_field(self, name, size):
        """Generate C field line for a bitfield (BF) type."""
        if isinstance(size, dict):
            bits_name = size.get("_bits_typedef_name", f"_{name}_bits_t")
            typedef_name = size.get("_typedef_name", f"{name}_t")
            ctype = typedef_name if bits_name != typedef_name else bits_name
        else:
            ctype = f"{name}_t"
        return f"\t{ctype} {name};"

    def _gen_union_field(self, name, size):
        """Generate C field line for a union (UNION) type."""
        if isinstance(size, dict):
            typedef_name = size.get("_typedef_name", f"{name}_t")
        else:
            typedef_name = str(size)
        return f"\t{typedef_name} {name};"

    def _gen_scalar_field(self, name, fmt, size, metadata):
        """Generate C field line for scalar types (B, H, I, s).

        Honors an optional ``ctype`` override (e.g. ``char`` or a pointer type)
        and an inline ``comment``, both carried in the metadata dict.
        """
        if fmt not in self.FORMAT_TO_CTYPE:
            raise ValueError(f"Unsupported format '{fmt}' for field '{name}'.")

        meta = metadata if isinstance(metadata, dict) else {}
        ctype = meta.get("ctype", self.FORMAT_TO_CTYPE[fmt])
        comment = meta.get("comment")
        suffix = f" /* {comment} */" if comment else ""

        if fmt == "s":
            if size is None:
                raise ValueError(f"Field '{name}' has format 's' but no array size.")
            return f"\t{ctype} {name}[{size}];{suffix}"

        if "bitfield_width" in meta:
            width = meta["bitfield_width"]
            return f"\t{ctype} {name}: {width};{suffix}"

        return f"\t{ctype} {name};{suffix}"

    def _schema_field_to_c(self, field_info):
        """Convert a schema field tuple to a C struct member string.

        BF fields reference the auto-generated bits struct type. UNION fields
        reference the auto-generated typedef union from union_dict.
        """
        name = field_info[0]
        fmt = field_info[1]
        size = field_info[2]
        metadata = field_info[3] if len(field_info) > 3 else {}

        if fmt == "BF":
            return self._gen_bf_field(name, size)
        if fmt == "UNION":
            return self._gen_union_field(name, size)
        return self._gen_scalar_field(name, fmt, size, metadata)

    @staticmethod
    def process_defines(gen, defines_list):
        """Process and generate #defines from defines list.

        Groups defines into sections to control blank line positioning.
        Handles:
        - Regular defines (with value)
        - Comments (via 'comment' field, supports \\n for multiline)
        - Blank lines before defines (via 'blank_line_before' field)

        Args:
            gen: HeaderGenerator instance
            defines_list: List of define dictionaries
        """
        current_section_defines = []
        current_leading_lines = []

        for define_entry in defines_list:
            define_name = define_entry.get("name")
            define_value = define_entry.get("value")
            comment = define_entry.get("comment", "")
            blank_line_before = define_entry.get("blank_line_before", False)

            if not define_name:
                continue

            # If blank_line_before is True, flush current section and start new one
            if blank_line_before and current_section_defines:
                # Add current section
                gen.add_section(
                    HeaderSection(
                        leading_lines=current_leading_lines,
                        defines=current_section_defines,
                        schema=[],
                        struct_name="",
                        skip_struct=True,
                    )
                )
                # Reset and add blank line marker
                current_section_defines = []
                current_leading_lines = [""]  # Blank line before next section

            # Build leading lines for this define
            define_leading_lines = []

            # Add comment if provided (support both string and array formats)
            if comment:
                # Handle both string and array formats
                if isinstance(comment, list):
                    # Array format: each element is a separate line
                    # Strip trailing \n from each element
                    comment_lines = [line.rstrip("\n") for line in comment]
                else:
                    # String format: split by \n
                    comment_str = str(comment)
                    # Handle JSON escape sequences: replace \\n with actual newline
                    comment_str = comment_str.replace("\\n", "\n")
                    # Split comment by newlines
                    comment_lines = comment_str.split("\n")

                # Add comment lines (skip empty ones)
                for line in comment_lines:
                    if line.strip():  # Skip empty lines
                        define_leading_lines.append(f"// {line}")

            # Add to current section
            if not current_leading_lines and define_leading_lines:
                current_leading_lines = define_leading_lines

            if define_value:
                current_section_defines.append((define_name, int(define_value, 16)))

        # Flush remaining section
        if current_section_defines:
            gen.add_section(
                HeaderSection(
                    leading_lines=current_leading_lines,
                    defines=current_section_defines,
                    schema=[],
                    struct_name="",
                    skip_struct=True,
                )
            )

    @staticmethod
    def process_enum(gen, enum_name, enum_config):
        """Process and generate an enum definition.

        Args:
            gen: HeaderGenerator instance
            enum_name: Enum name (typedef name, or tag name when ``typedef`` is
                       False) from the schema key.
            enum_config: Enum configuration dict with ``values``. Optional keys:
                         - ``comment``: leading Doxygen comment for the enum
                         - ``typedef``: if False, emit a tagged
                           ``enum NAME { }`` instead of
                           ``typedef enum { } NAME;`` (default True)
                         - each value may carry ``comment`` and
                           ``blank_line_before``

        Note: No automatic blank lines between values. Control spacing via each
        value's ``blank_line_before``.
        """
        values = enum_config.get("values", [])
        if not values:
            return

        use_typedef = enum_config.get("typedef", True)

        # Build enum definition
        enum_lines = []

        # Add blank line before if requested (no trailing blank line)
        if enum_config.get("blank_line_before", False):
            enum_lines.append("")

        if enum_config.get("comment"):
            enum_lines.extend(
                HeaderGenerator._format_doxygen_lines(enum_config["comment"])
            )

        if use_typedef:
            enum_lines.append("typedef enum {")
        else:
            enum_lines.append(f"enum {enum_name} {{")

        for value_entry in values:
            if value_entry.get("blank_line_before"):
                enum_lines.append("")
            if value_entry.get("comment"):
                enum_lines.extend(
                    "\t" + line
                    for line in HeaderGenerator._format_doxygen_lines(
                        value_entry["comment"]
                    )
                )
            val_name = value_entry.get("name")
            val_num = value_entry.get("value")
            if val_name is not None and val_num is not None:
                enum_lines.append(f"\t{val_name} = {val_num},")

        if use_typedef:
            enum_lines.append(f"}} {enum_name};")
        else:
            enum_lines.append("};")

        gen.add_section(
            HeaderSection(
                defines=[],
                pre_struct_lines=enum_lines,
                schema=[],
                struct_name="",
                skip_struct=True,
            )
        )

    @staticmethod
    def process_raw(gen, raw_config):
        """Emit verbatim C lines (e.g. a macro) as a standalone section.

        Args:
            gen: HeaderGenerator instance
            raw_config: Dict with optional ``comment``/``blank_line_before`` and
                        a ``lines`` list of verbatim C source lines.
        """
        lines = []
        if raw_config.get("blank_line_before"):
            lines.append("")
        if raw_config.get("comment"):
            lines.extend(HeaderGenerator._format_doxygen_lines(raw_config["comment"]))
        lines.extend(raw_config.get("lines", []))
        if not lines:
            return
        gen.add_section(
            HeaderSection(
                defines=[],
                pre_struct_lines=lines,
                schema=[],
                struct_name="",
                skip_struct=True,
            )
        )

    @staticmethod
    def process_union(gen, union_name, union_config, schema_loader):
        """Process and generate a standalone typedef union definition.

        Args:
            gen: HeaderGenerator instance
            union_name: Union typedef name (from schema key)
            union_config: Union configuration dict with ``members``
            schema_loader: SchemaLoader instance to convert members to schema
        """
        leading_lines = []
        if union_config.get("blank_line_before"):
            leading_lines.append("")
        comment = union_config.get("comment", "")
        if comment:
            leading_lines.append(f"// {comment}")

        union_dict = schema_loader.convert_union_to_dict(union_config)
        union_dict.setdefault("_typedef_name", union_name)
        union_lines = gen._gen_union_typedef(  # pylint: disable=protected-access
            union_name, union_dict
        )

        gen.add_section(
            HeaderSection(
                defines=[],
                pre_struct_lines=leading_lines + union_lines,
                schema=[],
                struct_name="",
                skip_struct=True,
            )
        )

    @staticmethod
    def process_struct(gen, struct_name, struct_config, schema_loader):
        """Process and generate a struct definition.

        Args:
            gen: HeaderGenerator instance
            struct_name: Struct typedef name (from schema key)
            struct_config: Struct configuration dict with 'fields'
            schema_loader: SchemaLoader instance to convert fields to schema

        Note: struct_name (the key) is used directly as the struct typedef name.
        """
        # Build leading lines
        leading_lines = []

        # Add blank line before if requested
        blank_line_before = struct_config.get("blank_line_before", False)
        if blank_line_before:
            leading_lines.append("")

        # Extract comment
        comment = struct_config.get("comment", "")
        if comment:
            leading_lines.append(f"// {comment}")

        # Get fields and convert to schema
        fields = struct_config.get("fields", [])
        schema = schema_loader.convert_fields_to_schema(fields) if fields else []

        # Extract field comments from bitfield definitions
        field_comments = HeaderGenerator.extract_comments(schema)

        # Generate struct
        gen.add_section(
            HeaderSection(
                leading_lines=leading_lines,
                defines=[],
                schema=schema,
                struct_name=struct_name,
                field_comments=field_comments,
            )
        )

    @staticmethod
    def extract_comments(schema_fields):
        """Extract comments from bitfield sub-fields for inline display.

        Args:
            schema_fields: List of field definitions (converted schema tuples)

        Returns:
            Dict mapping field names to comment strings
        """
        field_comments = {}

        for schema_field in schema_fields:
            if len(schema_field) < 3:
                continue

            fmt = schema_field[1]
            if fmt != "BF":
                continue

            # For bitfield, extract comments from sub-fields
            bf_dict = schema_field[2]
            if not isinstance(bf_dict, dict):
                continue

            # Look for comments in bitfields dict
            # Bitfield tuple format is always: (bit_pos, mask, comment)
            # comment can be None if not present in schema
            for bf_name, bf_info in bf_dict.items():
                # Skip metadata fields (start with '_')
                if bf_name.startswith("_"):
                    continue

                # Extract comment from 3-tuple (bit_pos, mask, comment)
                if isinstance(bf_info, (tuple, list)) and len(bf_info) >= 3:
                    comment = bf_info[2]
                    # Only add if comment exists and is not None
                    if comment and isinstance(comment, str):
                        field_comments[bf_name] = f"// {comment}"

        return field_comments
