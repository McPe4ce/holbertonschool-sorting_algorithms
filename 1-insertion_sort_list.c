#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to head of list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		key = current;
		current = current->next;

		while (key->prev && key->n < key->prev->n)
		{
			listint_t *prev = key->prev;

			/* Detach key */
			prev->next = key->next;
			if (key->next)
				key->next->prev = prev;

			/* Insert key before prev */
			key->prev = prev->prev;
			key->next = prev;

			if (prev->prev)
				prev->prev->next = key;
			else
				*list = key;

			prev->prev = key;

			print_list(*list);
		}
	}
}
