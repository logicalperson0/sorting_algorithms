#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers in
 * ascending order using the Counting sort algorithm
 *
 * @array: to be sorted
 * @size: of array
 */
void counting_sort(int *array, size_t size)
{
	size_t x;
	int *mall, *fin, y = 0;

	if (size < 2)
		return;
	for (x = 0; x < size; x++)
		if (y < array[x])
			y = array[x];

	mall = malloc(sizeof(int) * (y + 1));
	if (mall == NULL)
		return;
	for (x = 0; x < (size_t)(y + 1); x++)
		mall[x] = 0;
	/*store mall of each char*/
	for (x = 0; x < size; x++)
		mall[array[x]]++;

	/*change mall[x] so mall[x] now has actual position of this char*/
	for (x = 1; x < (size_t)(y + 1); x++)
		mall[x] += mall[x - 1];
	print_array(mall, y + 1);

	fin = malloc(sizeof(int) * (size + 1));
	if (fin == NULL)
	{
		free(mall);
		return;
	}
	/*output char of array*/
	for (x = 0; x < size; x++)
	{
		fin[mall[array[x]] - 1] = array[x];
		mall[array[x]]--;
	}
	/*copy fin array to array so array contains sorted chars*/
	for (x = 0; x < size; x++)
		array[x] = fin[x];
	free(mall);
	free(fin);
}
