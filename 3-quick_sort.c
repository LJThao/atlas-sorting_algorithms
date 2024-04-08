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
 * l_partition - implementing the quicksort
 * @array: array of integer
 * @size: size of arrays
 * @left: beginning integer
 * @right: ending integer
 * Return: partition index
*/

int l_partition(int *array, size_t size, int left, int right)
{
	int *element, a, b;

	element = array + right;

	for (a = b = left; b < right; b++)
	{
		if (array[b] < *element)
		{
			if (a < b)
			{
				int_swap(array + b, array + a);
				print_array(array, size);
			}
			a++;
		}
	}
	if (array[a] > *element)
	{
		int_swap(array + a, element);
		print_array(array, size);
	}
	return (a);
}

/**
 * lomuto - implementing the lomuto partition scheme 
 * @array: array of int
 * @size: size of the array
 * @left: start of index
 * @right: the end of index
 */

void lomuto(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = l_partition(array, size, left, right);
		lomuto(array, size, left, p - 1);
		lomuto(array, size, p + 1, right);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending order using quick sort
 * @array: array
 * @size: size
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
		return;

        lomuto(array, size, 0, size - 1);
}
