#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @array: Pointer to the array.
 * @idx1: Index of the first element.
 * @idx2: Index of the second element.
 */
void swap(int *array, size_t idx1, size_t idx2)
{
    int tmp;

    tmp = array[idx1];
    array[idx1] = array[idx2];
    array[idx2] = tmp;
}

/**
 * Lomuto - Partition function for Quick Sort algorithm (Lomuto scheme).
 * @array: Pointer to the array to be sorted.
 * @lr: Lower bound of the array or subarray.
 * @ur: Upper bound of the array or subarray.
 * @size: Size of the array.
 *
 * Return: The final position of the pivot element.
 */
size_t Lomuto(int *array, size_t lr, size_t ur, size_t size)
{
    int pivot;
    size_t start, end;

    pivot = array[ur];
    start = lr;

    for (end = lr; end < ur; end++)
    {
        if (array[end] < pivot)
        {
            if (start != end)
            {
                swap(array, start, end);
            }
            start++;
        }
    }

    swap(array, start, ur);
    print_array(array, size);
    return start;
}

/**
 * qs - Recursive function to perform Quick Sort.
 * @array: Pointer to the array to be sorted.
 * @lr: Lower bound of the array or subarray.
 * @up: Upper bound of the array or subarray.
 * @size: Size of the array.
 */
void qs(int *array, size_t lr, size_t up, size_t size)
{
    size_t clocl;

    if (lr < up)
    {
        clocl = Lomuto(array, lr, up, size);
        if (clocl != up)
        {
            qs(array, clocl, up, size);
        }
        if (clocl != lr)
        {
            qs(array, lr, clocl - 1, size);
        }
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
