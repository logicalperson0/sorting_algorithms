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
	unsigned long int mini, x = 0, y;

	if (size == 0)
		return;

	while (x < size - 1)
	{
		mini = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[mini])
				mini = y;
			if (mini != x)
			{
				swapping(&array[mini], &array[x]);
			}

		}
		print_array(array, size);
		x++;
	}
}
