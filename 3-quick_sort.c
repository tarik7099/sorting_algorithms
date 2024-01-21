#include "sort.h"

/**
* swap - Swaps two integers.
* @item1: Pointer to the first integer.
* @item2: Pointer to the second integer.
*/
void swap(int *item1, int *item2)
{
int tmp;

tmp = *item1;
*item1 = *item2;
*item2 = tmp;
}

/**
* Lomuto - Partition function for Quick Sort algorithm (Lomuto scheme).
* @array: Pointer to the array to be sorted.
* @lr: Lower bound of the array or subarray.
* @ur: Upper bound of the array or subarray.
* @size: size
* Return: The final position of the pivot element.
*/
ssize_t Lomuto(int *array, ssize_t lr, ssize_t ur, size_t size)
{
int pivot;
ssize_t start, end;

pivot = array[ur];

start = lr;
end = ur - 1;

while (start <= end)
{
while (start <= end && array[start] < pivot)
start++;

while (start <= end && array[end] > pivot)
end--;

if (start < end)
{
swap(&array[start], &array[end]);
print_array(array, size);
start++;
end--;
}
}

swap(&array[start], &array[ur]);
print_array(array, size);

return (start);
}

/**
* qs - Recursive function to perform Quick Sort.
* @array: Pointer to the array to be sorted.
* @lr: Lower bound of the array or subarray.
* @up: Upper bound of the array or subarray.
* @size: size
*/
void qs(int *array, ssize_t lr, ssize_t up, size_t size)
{
ssize_t clocl;

if (lr < up)
{
clocl = Lomuto(array, lr, up, size);
qs(array, lr, clocl - 1, size);
qs(array, clocl + 1, up, size);
}
}

/**
* quick_sort - Sorts an array of integers using the Quick Sort algorithm.
* @array: Pointer to the array to be sorted.
* @size: Size of the array.
*/
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;
qs(array, 0, size - 1, size);
}
