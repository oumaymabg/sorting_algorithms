#include "sort.h"

/**
 * bubble_sort - sorts an array of ints in ascending order
 * @array: the array being sorted
 * @size: the size of the array
 *
 * Return: void.
**/
void bubble_sort(int *array, size_t size)
{
size_t i, j;
for (i = 0; i < size; i++)
{
for (j = 0; j < size - 1; j++)
{
if (array[j] > array[j + 1])
{
integer_swap(&array[j], &array[j + 1]);
print_array(array, size);
}
}

j++;
}
}


/**
 * integer_swap - Swaps integers
 * @fst : first integer
 * @snd : second integer
 *
**/
void integer_swap(int *fst, int *snd)
{
int temp = *fst;
*fst = *snd;
*snd = temp;
}
