#include "sort.h"

/**
 * find_max - Find the maximum integer in an array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 *
 * Return: The maximum integer found in the array.
 */
size_t find_max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
		if (max < array[i])
			max = array[i];

	return (max);
}

/**
 * create_count_array - Create an array for counting occurrences.
 * @array: Input array to be sorted.
 * @size: Size of the input and count arrays.
 * @max: The maximum value in the input array.
 *
 * Return: A dynamically allocated integer array initialized to zero.
 */
int *create_count_array(int *array, size_t size, size_t max)
{
	size_t i;
	int index;
	int *count_array = malloc(sizeof(int) * (max + 1));

	/* Initialize count_array to 0 */
	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	/* Store the count of each unique element of the input array */
	for (i = 0; i < size; i++)
	{
		index = array[i];
		count_array[index]++;
	}

	/* Store the cumulative sum of prefix sum */
	/* of the elements of the count_array. */
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];

	return (count_array);
}

/**
 * create_output_array - Create output array based on count and input arrays.
 * @array: Input array to be sorted.
 * @count_array: Array containing element counts.
 * @size: Size of the input and count arrays.
 *
 * Return: A dynamically allocated integer array with sorted values.
 */
int *create_output_array(int *array, int *count_array, size_t size)
{
	int i;
	int *output = malloc(sizeof(int) * size);
	int value, index;

	for (i = size - 1; i >= 0; i--)
	{
		value = array[i];
		index = count_array[value] - 1;
		output[index] = value;
		count_array[value]--;
	}

	return (output);
}

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, max;
	int *count_array, *sorted;

	if (!array || size < 2)
		return;

	max = find_max(array, size);
	count_array = create_count_array(array, size, max);
	print_array(count_array, max + 1);
	sorted = create_output_array(array, count_array, size);

	for (i = 0; i < size; i++)
		array[i] = sorted[i];
}
