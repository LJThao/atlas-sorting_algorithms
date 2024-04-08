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
 * @low: low integer
 * @high: high integer
 * Return: partition index
*/

int l_partition(int *array, int low, int high)
{
        int sort = array[high];
        int a = low - 1;
        int b = 0;

        for (b = low; b < high; b++)
        {
                if (array[b] < sort)
                {
                        b++;
                        int_swap(&array[a], &array[b]);
                }
        }
        print_array(array, high - low + 1);
        int_swap(&array[a + 1], &array[high]);
        return (a + 1);
}

/**
 * lomuto - implementing the lomuto partition scheme 
 * @array: array of int
 * @low: low integer
 * @high: high integer
 * Return: 0
 */

void lomuto(int *array, size_t size, int low, int high)
{
	int p;

	if (high - low > 0)
	{
		p = l_partition(array, low, high);
		lomuto(array, size, low, p - 1);
		lomuto(array, size, p + 1, high);
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

