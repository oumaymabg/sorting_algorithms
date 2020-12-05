#ifndef SORT_H
#define SORT_H

#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int quick_sorter(int *array, int lo, int hi, size_t size);
int partition(int *array, int lo, int hi, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
size_t dlistint_len(const listint_t *h);
void sort_right(listint_t *head, listint_t **list);
void sort_left(listint_t *head, listint_t **list);
void counting_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void h_helper(int *array, size_t size, int lo, int hi);
int h_partition(int *array, size_t size, int lo, int hi);
void quick_sort_hoare(int *array, size_t size);
#endif