#!/usr/bin/python3
""" function minOperations
    """


def minOperations(n):
    """minimum operations for action
    Args:
        n (int): input
    Returns:
        int:  number of operations
    """

    numn_op = 0
    oper = 2

    if n <= 1:
        return 0

    while n > 1:
        if n % oper == 0:
            n = n / oper
            numn_op = numn_op + oper
        else:
            oper += 1
    return numn_op
