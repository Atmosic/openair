'''
@file atm_west_utils.py

@brief Common utility functions for Atmosic west extensions

Copyright (c) Atmosic 2024
'''

from enum import Enum

class TermColors(Enum):
    """Terminal Colors for pretty printing
    """
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    RED = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    MAGENTA = '\u001b[35m'


def wrap_color(print_str: str, color: TermColors) -> str:
    """wrap a string in a specific terminal color

    Args:
        print_str (str): string to wrap in a color
        color (TermColors): Terminal color

    Returns:
        str: colorified string
    """
    return f"{color.value}{print_str}{TermColors.ENDC.value}"

