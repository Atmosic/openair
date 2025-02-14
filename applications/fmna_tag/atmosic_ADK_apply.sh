#!/bin/bash

# Ensure the script stops on failure
set -e

# Define variables
ZIP_FILE="Find My network ADK 1.0.zip"
EXTRACT_DIR="adk_extracted"
TARGET_DIR="openair/lib/fmna"
PATCH_FILE="atmosic_ADK.patch"

# Check if the required files exist
if [[ ! -f "$ZIP_FILE" ]]; then
	echo "Error: ZIP file not found: $ZIP_FILE"
	exit 1
fi

if [[ ! -f "$PATCH_FILE" ]]; then
	echo "Error: Patch file not found: $PATCH_FILE"
	exit 1
fi

# Unzip the ZIP file
echo "Unzipping $ZIP_FILE..."
mkdir -p "$EXTRACT_DIR"
unzip -q "$ZIP_FILE" -d "$EXTRACT_DIR"

# Ensure the target directory exists
echo "Ensuring target directory $TARGET_DIR..."
mkdir -p "$TARGET_DIR/crypto"

# Copy files
echo "Copy files to $TARGET_DIR..."
cp -r "$EXTRACT_DIR/findmy_network_adk/src" "$TARGET_DIR/"
cp -r "$EXTRACT_DIR/findmy_network_adk/UARPDK" "$TARGET_DIR/"
cp "$EXTRACT_DIR/findmy_network_adk/License.rtf" "$TARGET_DIR/"
cp "$EXTRACT_DIR/findmy_network_adk/crypto/fmna-crypto-wrapper-reference/include/fm-crypto.h" "$TARGET_DIR/crypto/"

# Apply the patch file
echo "Applying patch file..."
patch -p3 -d "$TARGET_DIR" < "$PATCH_FILE"

file="openair/lib/CMakeLists.txt"
line_to_add="add_subdirectory(fmna)"

echo "Add fmna lib into CMakeLists.txt..."
grep -Fxq "$line_to_add" "$file" || echo "$line_to_add" >> "$file"

# Clean up temporary files
echo "Cleaning up temporary files..."
rm -rf "$EXTRACT_DIR"

echo "Process completed!"
