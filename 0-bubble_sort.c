#include "sort.h"

/**
 * bubble_sort - Sorts an array bubble way
 * Means it will check if the next value in the array
 * is smaller than the current one. if yes it will be swapped
 * and will start from the beginning afterwards until done
 * @array: Array that stores the values
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t verificator;
	size_t index;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (verificator = 0; verificator < size - 1; verificator++)
	{
		for (index = 0; index < size - 1 - verificator; index++)
		{
			if (array[index] > array[index + 1])
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
