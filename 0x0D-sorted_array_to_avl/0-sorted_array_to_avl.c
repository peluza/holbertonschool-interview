#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @index: number for interection in the array
 * @array: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
avl_t *binary_tree_node(avl_t *parent, int index, int *array)
{
	avl_t *new_node;

	/*Allocate memory for new node*/
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	/*Assign data to this node*/
	new_node->n = array[index];

	/*The parent of the new node is the same as the parent(root)*/
	new_node->parent = parent;
	/*Initialize left and right children as NULL*/
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

/**
 * *sorted_array_to_avl - builds an AVL tree from an array
 * @array: The array to be printed
 * @size: Size of the array
 * Return: binary tree on success, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_node = NULL;

	if (!array || !size)
		return (NULL);


	new_node = SortedArrayToAVL(array, 0, size - 1, NULL);
	return (new_node);
}

/**
 * *SortedArrayToAVL - builds an AVL tree from an array
 * @array: The array to be printed
 * @start: Start size of the array
 * @end: end size of the array
 * @root: array of the struct
 * Return: binary tree on success, NULL on failure
 */
avl_t *SortedArrayToAVL(int *array, size_t start, size_t end, avl_t *root)
{
	size_t mid;
	avl_t *new_node = NULL;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	new_node = binary_tree_node(root, mid, array);
	if (!new_node)
		return (NULL);
	if (mid != start)
		new_node->left = SortedArrayToAVL(array, start, mid - 1,
				new_node);
	if (mid != end)
		new_node->right = SortedArrayToAVL(array, mid + 1, end,
				new_node);
	return (new_node);
}
