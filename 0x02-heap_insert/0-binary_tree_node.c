#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/*Allocate memory for new node*/
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	/*Assign data to this node*/
	new_node->n = value;

	/*The parent of the new node is the same as the parent(root)*/
	new_node->parent = parent;
	/*Initialize left and right children as NULL*/
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
