#include "sort.h"

/**
 * selection_sort - Sorts an array using the selection style
 * Meaning it will scan the array to find the smallest value
 * If that value isnt at array[0], swap once
 * Restart at pos1, and repeat until it is sorted
 * @array: Array that stores the values
 * @size: Size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t index;
	size_t lil_index;
	size_t dedex;
	int temp;

	for (index = 0; index < size - 1; index++)
	{
		lil_index = index;

		for (dedex = index + 1; dedex < size; dedex++)
		{
			if (array[dedex] < array[lil_index])
			{
				lil_index = dedex;
			}
		}
		if (lil_index != index)
		{
			temp = array[index];
			array[index] = array[lil_index];
			array[lil_index] = temp;
			print_array(array, size);
		}
	}
}
