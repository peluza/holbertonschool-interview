#!/usr/bin/python3


def canUnlockAll(boxes):
    """determines if all the boxes can be opened.

    Args:
        boxes (list):  is a list of lists

    Returns:
        bool: Return True if all boxes can be opened, else return False
    """
    rank = {0: 0}
    each = 0
    while each < len(boxes):
        if rank.get(each) != each:
            return False
        for key in boxes[each]:
            if key < len(boxes) and rank.get(key) != key:
                rank[key] = key
                for box in boxes[key]:
                    if box < len(boxes) and rank.get(box) != box:
                        rank[box] = box
        each += 1
    return True
