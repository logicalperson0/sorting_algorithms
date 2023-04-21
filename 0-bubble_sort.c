#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: the arr to be sorted
 * @size: size of the arr
 *
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int x, y;

	if (size == 0)
		return;

	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				swapping(&array[y], &array[y + 1]);
				print_array(array, size);
			}
		}
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
