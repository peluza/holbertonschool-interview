#!/usr/bin/python3
"""validUTF-8"""


def validUTF8(data):
    """validate if the characters in the list are utf-8

    Args:
        data (list): numbers

    Returns:
        [bool]:  if utf-8 return true
    """
    if not isinstance(data, list):
        return
    if len(data) == 0:
        return True
    count = 0
    for c in data:
        if count == 0:
            if (c >> 5) == 0b110:
                count = 1
            elif (c >> 4) == 0b1110:
                count = 2
            elif (c >> 3) == 0b11110:
                count = 3
            elif (c >> 7):
                return False
        else:
            if (c >> 6) != 0b10:
                return False
            count -= 1
    return True
