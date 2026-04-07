#include "sort.h"

void bubble_sort(int *array, size_t size)
{
    int verificator;
    int index;
    int temp;

    if (array == NULL || size < 2)
    {
        return (NULL);
    }

    for (verificator = 0; verificator < size - 1; verificator++)
    {
        for (index = 0; index < size - 1 - verificator; index++)
        {
            if (array[verificator] > array[verificator + 1])
            {
                temp = array[index];
                array[index] = array[index + 1];
                array[index + 1] = temp;
                print_array(array, size);
            }
        }
    }
}