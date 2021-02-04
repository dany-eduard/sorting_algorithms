#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * partition - swap the numbers
 * @arr: the array
 * @low: lowest number
 * @high: higher number
 * @size: size of the array
 * Return: the position
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1), j;
	int temp;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	print_array(arr, size);
	return (i + 1);
}
/**
 * quickSort - look for the smallest
 * @arr: the array with the numbers
 * @low: lower number
 * @high: higher number
 * @size: size of the array
 */
void quickSort(int arr[], int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high, size);

		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
	}
}
/**
 * quick_sort - sort selection
 * @array: the array list
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quickSort(array, 0, size, size);
}
