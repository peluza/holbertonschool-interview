#!/usr/bin/python3
"""rain"""


def rain(walls):
    """rain

    Args:
        walls (list): is a list of non-negative integers.

    Returns:
        [type]: Integer indicating total amount of rainwater retained.
    """
    if walls is None:
        return 0

    LenWalls = len(walls)
    EndWalls = LenWalls - 1
    TotalWalter = 0

    for i in range(1, EndWalls):
        Left = walls[i]
        for j in range(i):
            Left = max(walls[j], Left)
        Rigth = walls[i]
        start = i + 1
        for j in range(start, LenWalls):
            Rigth = max(walls[j], Rigth)

        MinWlater = min(Left, Rigth) - walls[i]
        TotalWalter = TotalWalter + MinWlater

    return TotalWalter
