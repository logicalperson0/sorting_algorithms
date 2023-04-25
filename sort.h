#ifndef _sort_h_
#define _sort_h_

#include <stdlib.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Prints the integers*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void swapping(int *prev, int *next);

/*bubble sort algorithms*/
void bubble_sort(int *array, size_t size);

/*Insertion sort algorithm*/
void insertion_sort_list(listint_t **list);

/*Selection sort algorithm*/
void selection_sort(int *array, size_t size);

/*Quick sort algorithm*/
void quick_sort(int *array, size_t size);
void quick_rec(int *arr, int small, int big, int size);
int pivot(int *arr, int small, int big, int size);

/*shell sort algorithm*/
void shell_sort(int *array, size_t size);

/*cocktail_sort*/
void cocktail_sort_list(listint_t **list);
bool forward_s(listint_t **lists, bool z);
bool backward_s(listint_t **lists, bool z);

void counting_sort(int *array, size_t size);

#endif
