#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: array to be sorted
 * @size: size of arr
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t x, y, z;
	int c;

	for (x = 1; x < size; x = x * 3 + 1)
		;
	while ((x = (x - 1) / 3) > 0)
	{
		for (y = x; y < size; y++)
		{
			c = array[y];
			for (z = y; z >= x && array[z - x] > c; z -= x)
				array[z] = array[z - x];
			array[z] = c;
		}
		print_array(array, size);
	}
}
