#include "sort.h"
#include <stdio.h>
/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: array to be sorted
 * @size: num of elements in arr
 *
 */
void quick_sort(int *array, size_t size)
{
	if (size == 0)
		return;

	quick_rec(array, 0, size - 1, size);
}

/**
 * quick_rec - recursively divides the arr around the pivot
 *
 * @arr: array to be divided
 * @small: low pt of the array
 * @big: high pt of the array
 * @size: size of arr
 */
void quick_rec(int *arr, int small, int big, int size)
{
	int p;

	if (small < big)
	{
		p = pivot(arr, small, big, size);
		/*to recursively sort to elements < p*/
		quick_rec(arr, small, p - 1, size);
		/*to recursively sort to elements > p*/
		quick_rec(arr, p + 1, big, size);
	}
}

/**
 * pivot - the num around which the array divides itself
 *
 * @arr: array to be divided
 * @small: low pt of the array
 * @big: high pt of the array
 * @size: size of arr
 * Return: pivot number
 */
int pivot(int *arr, int small, int big, int size)
{
	int x, y, piv;

	piv = arr[big];
	x = small;

	for (y = small; y < big; y++)
	{
		if (arr[y] <= piv)
		{
			if (y != x)
			{
				swapping(&arr[x], &arr[y]);
				print_array(arr, size);
			}
			x++;
		}

	}
	if (arr[x] != piv)
	{
		swapping(&arr[x], &arr[big]);
		print_array(arr, size);
	}

	return (x);
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
