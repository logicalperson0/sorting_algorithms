#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort
 *
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	bool b = true;

	if (list == NULL)
		return;

	while (b)
	{
		b = false;
		b = forward_s(list, b);

		if (b == false)
			break;
		b = false;

		b = backward_s(list, b);
	}
}

/**
 * forward_s - func that moves forward dir
 *
 * @lists: listint_t type
 * @z: bool type
 * Return: z
 */
bool forward_s(listint_t **lists, bool z)
{
	listint_t *tempo, *news = *lists;

	while (news != NULL && news->next != NULL)
	{
		if (news->n > news->next->n)
		{
			tempo = news->next;
			news->next = tempo->next;
			tempo->prev = news->prev;

			if (news->prev != NULL)
				news->prev->next = tempo;
			news->prev = tempo;

			if (tempo->next != NULL)
				tempo->next->prev = news;
			tempo->next = news;

			if (tempo->prev == NULL)
				*lists = tempo;
			else
				news = tempo->prev;

			print_list(*lists);
			z = true;
		}
		news = news->next;
	}
	return (z);
}

/**
 * backward_s - func that moves backward
 * @lists: listint_t type
 * @z: bool type
 * Return: z
 */
bool backward_s(listint_t **lists, bool z)
{
	listint_t *tempo, *x = *lists;

	while (x->next != NULL)
		x = x->next;

	while (x != NULL && x->prev != NULL)
	{

		if (x->n < x->prev->n)
		{
			tempo = x->prev;
			x->prev = tempo->prev;
			tempo->next = x->next;

			if (x->next != NULL)
				x->next->prev = tempo;
			x->next = tempo;

			if (tempo->prev != NULL)
				tempo->prev->next = x;
			tempo->prev = x;

			if (tempo->prev->prev == NULL)
				*lists = tempo->prev;
			else
				x = tempo->next;
			print_list(*lists);
			z = true;
		}
		x = x->prev;
	}
	return (z);
}
