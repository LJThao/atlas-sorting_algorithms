#include "sort.h"

/**
 * int_swap - ints swap
 * @a: First int to swap
 * @b: Second int to swap
 * Return: 0
 */

void int_swap(int *a, int *b)
{
        int tmp = *a;
        *a = *b;
        *b = tmp;
}

/**
 * bubble_sort - function that sorts an array of ints using bubble sort.
 * @array: array
 * @size: size  
 * Return: 0
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, b;

	if (array == NULL || size == 0)
		return;

	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
			int_swap(&array[b], &array[b + 1]);
			print_array(array, size);
			}
		}
	}
}
