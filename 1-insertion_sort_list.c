#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 *
 * @list: of type listint_t to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	/*int x;*/
	listint_t *new = *list, *tempo;

	if (*list == NULL)
		return;

	while (new != NULL)
	{
		/*x = new->next->n;*/
		while (new->next != NULL && (new->n > new->next->n))
		{
			tempo = new->next;
			new->next = tempo->next;
			tempo->prev = new->prev;

			if (new->prev != NULL)
				new->prev->next = tempo;
			new->prev = tempo;

			if (tempo->next != NULL)
				tempo->next->prev = new;
			tempo->next = new;

			if (tempo->prev == NULL)
				*list = tempo;
			else
				new = tempo->prev;

			print_list(*list);
		}
		new = new->next;
	}
}
