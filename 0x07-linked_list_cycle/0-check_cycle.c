#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: List for structure
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *list_1, *list_2;

	list_1 = list;
	list_2 = list;

	while (list_1 != NULL && list_2 != NULL && list_2->next != NULL)
	{
		list_2 = list_2->next->next;
		list_1 = list_1->next;

		if (list_1 == list_2)
		{
			return (1);
		}
	}
	return (0);
}
