#include "lists.h"

/**
 * reverse - recursive function
 * @head_1: pointer to head of list
 * @head_2: pointer to the list
 *
 * Return: tmp
 */

int reverse(listint_t **head_1, listint_t *head_2)
{
	int tmp;

	if (head_2 == NULL)
		return (1);

	tmp = reverse(head_1, head_2->next);
	if (tmp == 0)
		return (0);

	tmp = (head_2->n == (*head_1)->n);
	*head_1 = (*head_1)->next;

	return (tmp);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{

	if (head == NULL)
		return (0);
	return (reverse(head, *head));
}
