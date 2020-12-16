#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * *insert_node - listint_t *insert_node
 * @head: pointer to list to be freed
 * @number: value to insert
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
		*head = new;

	if ((*head)->n > new->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	while (current->next != NULL)
	{
		if (current->next->n < new->n)
			current = current->next;
		else
			break;
	}
	new->next = current->next;
	current->next = new;
	return (new);
}
