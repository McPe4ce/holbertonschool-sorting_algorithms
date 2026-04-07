#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to head of list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		insert = current;
		tmp = current->next;

		while (insert->prev && insert->n < insert->prev->n)
		{
			listint_t *prev = insert->prev;

			if (prev->prev)
				prev->prev->next = insert;
			insert->prev = prev->prev;

			prev->next = insert->next;
			if (insert->next)
				insert->next->prev = prev;

			insert->next = prev;
			prev->prev = insert;

			if (!insert->prev)
				*list = insert;

			print_list(*list);
		}

		current = tmp;
	}
}
