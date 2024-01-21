#include "sort.h"

/**
* swap - Swaps two elements in an array.
* @array: The array.
* @idx1: Index of the first element.
* @idx2: Index of the second element.
*/
void swap(int *array, ssize_t idx1, ssize_t idx2)
{
int tmp;

tmp = array[idx1];
array[idx1] = array[idx2];
array[idx2] = tmp;
}

/**
* lomuto_partition - Lomuto partition sorting scheme implementation.
* @array: The array.
* @low: Index of the first element.
* @high: Index of the last element.
* @size: Size of the array.
*
* Return: Return the position of the last element sorted.
*/
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
int pivot = array[high];
ssize_t current = low, explorer;

for (explorer = low; explorer < high; explorer++)
{
if (array[explorer] < pivot)
{
if (array[current] != array[explorer])
{
swap(array, current, explorer);
print_array(array, size);
}
current++;
}
}

if (array[current] != array[high])
{
swap(array, current, high);
print_array(array, size);
}

return (current);
}

/**
* qs - Quicksort algorithm implementation.
* @array: The array.
* @low: Index of the first element.
* @high: Index of the last element.
* @size: Size of the array.
*/
void qs(int *array, ssize_t low, ssize_t high, int size)
{
ssize_t position = 0;

if (low < high)
{
position = lomuto_partition(array, low, high, size);

qs(array, low, position - 1, size);
qs(array, position + 1, high, size);
}
}

/**
* quick_sort - Prepares the terrain for the quicksort algorithm.
* @array: The array.
* @size: Size of the array.
*/
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

qs(array, 0, size - 1, size);
}
