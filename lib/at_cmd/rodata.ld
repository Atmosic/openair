	. = ALIGN(4);
	__at_cmd_start = .;
	KEEP(*(SORT(.at_cmd.*)))
	__at_cmd_end = .;
