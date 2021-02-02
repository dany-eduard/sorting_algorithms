#include "sort.h"
/**
 * selection_sort - Selection sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp = 0, min_idx = 0;

	if (!array || size < 2)
		return;
	
	for (i = 0; i <= size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		tmp = array[min_idx];
		array[min_idx] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
}
