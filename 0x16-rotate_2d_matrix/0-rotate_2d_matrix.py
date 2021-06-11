#!/usr/bin/python3
"""rotate 2d matrix"""

def rotate_2d_matrix(matrix):
    """rotate_2d_matrix

    Args:
        matrix (list): list of the lists
    """
    new_matrix = []
    col = len(matrix) - 1
    len_m = len(matrix)
    for col in range(len_m):
        tmp = []
        for row in range(len_m-1, -1, -1):
            tmp.append(matrix[row][col])
        new_matrix.append(tmp)
    for i in range(len_m):
        for j in range(len_m):
            matrix[i][j] = new_matrix[i][j]
