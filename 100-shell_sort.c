#include "sort.h"

/**
 * swap - swap two elements
 * @a: pointer to the 1st element
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
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t inv, i, j;

	for (inv = 1; inv < size / 3; inv = inv * 3 + 1)
		;

	for (; inv > 0; inv = inv / 3)
	{
		for (i = inv; i < size; i++)
		{
			for (j = i; j >= inv && array[j - inv] > array[i]; j = j - inv)
			{

				swap(&array[j], &array[j - inv]);
				if (array[j] <= array[j + inv])
					break;
			}
		}

		print_array(array, size);
	}
}
