#include "sort.h"

/**
 * swap - Swap two element
 * @a: pointer to the 1s element to swap
 * @b: pointer to the 2d element
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto - Partitions an array using Lomuto scheme
 * @array: pointer to tha array
 * @low: Lowest index of the array
 * @high: highest index of the array
 * @size: lenght of the array
 *
 * Return: the index of the pivot element
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];

	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (j != i)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_helper - recusrsive helper for quick_sort
 * @array: pointer to the array
 * @low: lowest index of the array
 * @high: highest index of the array
 */
void quick_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto(array, low, high, size);
		/* print_array(array, high + 1); */
		quick_helper(array, low, pivot - 1, size);
		quick_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 * @array: pointer to the array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;

	if (array == NULL || size <= 1)
		return;

	quick_helper(array, low, high, size);
}
