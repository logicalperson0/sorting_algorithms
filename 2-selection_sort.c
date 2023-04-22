#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: array to be sorted
 * @size: num of elements in array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t min_i, x = 0, y;

	if (size == 0)
		return;

	while (x < size - 1)
	{
		min_i = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min_i])
				min_i = y;
		}
			if (min_i != x)
			{
				swapping(&array[min_i], &array[x]);
				print_array(array, size);
			}
		x++;
	}
}

/**
 * swapping - func that switches the prev and next elements
 * @prev: 1st para
 * @next: 2nd para
 *
 */
void swapping(int *prev, int *next)
{
	int tempo = *prev;

	*prev = *next;
	*next = tempo;
}
