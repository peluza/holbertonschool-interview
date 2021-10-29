#!/usr/bin/python3
""" Change comes from within"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins (list): list for number
        total (int): number

    Returns:
        int: fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0

    new = total + 1
    store = {0: 0}

    for i in range(1, total + 1):
        store[i] = new

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            store[i] = min(store[current] + 1, store[i])

    if store[total] == total + 1:
        return -1

    return store[total]
