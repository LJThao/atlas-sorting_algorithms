#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of ints
 * @list: list
 * Return: 0
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *data;
	listint_t *tp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	data = *list;

	while (data != NULL)
	{
		tp = data;

		while (tp->prev != NULL && tp->n < tp->prev->n)
		{
			if (tp->next != NULL)
			tp->next->prev = tp->prev;

			tp->prev->next = tp->next;
			tp->next = tp->prev;
			tp->prev = tp->prev->prev;
			tp->next->prev = tp;

			if (tp->prev != NULL)
			{
			tp->prev->next = tp;
			}
			else
			{
				*list = tp;
			}
			print_list(*list);
		}
			data = tp->next;
	}
}
