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
 * selection_sort - function that sorts an array of ints using the selection sort alg
 * @array: array
 * @size: size
 * Return: 0
 */

void selection_sort(int *array, size_t size)
{
	int *value;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		value = array + a;
		for (b = a + 1; b < size; b++)
			value = (array[b] < *value) ? (array + b) : value;

		if ((array + a) != value)
		{
			int_swap(array + a, value);
			print_array(array, size);
		}
	}
}
