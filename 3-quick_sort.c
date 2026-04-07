#include "sort.h"

/**
 * swap_int - swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */

void swap_int(int *a, int *b)
{
    if (*a != *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

/**
 * lomuto_partition - Lomuto partition for quicksort
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: array size (for printing)
 * Return: partition index
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap_int(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (i + 1 != high)
    {
        swap_int(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quick_sort_recursive - recursive quicksort
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: array size
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);

        quick_sort_recursive(array, low, pi - 1, size);
        quick_sort_recursive(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: array to sort
 * @size: array size
 */

void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
