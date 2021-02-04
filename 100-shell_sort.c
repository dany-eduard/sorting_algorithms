#include "sort.h"
/**
 * shell_sort - Shell sot algorithm.
 * @array: an array to sort.
 * @size: size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, gap = 0, check;
	int tmp;

	if (!array || !size || size < 2)
		return;

	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		check = 0;
		for (i = 0; i + gap < size; i++)
		{
			if (array[i] > array[i + gap])
			{
				tmp = array[i];
				array[i] = array[i + gap];
				array[i + gap] = tmp;
				check = 1;
			}
		}
		if (check == 0)
		{
			gap = (gap - 1) / 3;
			print_array(array, size);
		}
	}
}
