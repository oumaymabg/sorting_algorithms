#include "sort.h"

/**
* cocktail_sort_list - Creates a doubly linked list from an array of integers
*
* @list: Array to convert to a doubly linked list
*
*/
void cocktail_sort_list(listint_t **list)
{
	int flag = 1, len = 0, count = 0, flag_1 = 0, flag_2 = 0;
	listint_t *head = NULL;

	if (!list || !*list)
		return;
	head = *list, len = dlistint_len(*list);
	while (flag == 1)
	{
		while (count <= (len - 2))
		{
			if (head->n > head->next->n)
			{
				sort_right(head, list);
				flag = 1, flag_1 = 1;
			}
			if (flag_1 == 0)
				head = head->next;
			flag_1 = 0, count += 1;
		}
		if (flag == 0)
			break;
		flag = 0, count = count - 1;
		head = head->prev;
		while (count >= 0)
		{
			if (head->n > head->next->n)
			{
				sort_left(head, list);
				if (head->prev->prev != NULL)
					head = head->prev->prev;
				else
					head = head->prev;
				flag_2 = 1, flag = 1;
			}
		if (flag_2 == 0 && head->prev != NULL)
			head = head->prev;
		flag_2 = 0, count -= 1;
		}
		count = 0;
	}
}

/**
* dlistint_len - returns number elements of a dlistint list
* @h: head of the dlistint
*
* Return: the number of nodes
*/
size_t dlistint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
	h = h->next;
	count++;
	}
	return (count);
}

/**
* sort_right - Creates a doubly linked list from an array of integers
*
* @head: actual pointer
* @list: pointer to the array
*
*/
void sort_right(listint_t *head, listint_t **list)
{
	listint_t *tmp = NULL;

	tmp = head->next;
	head->next = head->next->next;
	if (head->next != NULL)
		head->next->prev = head;
	tmp->next = head;
	tmp->prev = head->prev;
	if (head->prev != NULL)
		head->prev->next = tmp;
	if (head->prev == NULL)
		*list = tmp;
	head->prev = tmp;
	print_list(*list);
}

/**
* sort_left - Creates a doubly linked list from an array of integers
*
* @head: actual pointer
* @list: pointer to the array
*
*/
void sort_left(listint_t *head, listint_t **list)
{
	listint_t *tmp = NULL;

	tmp = head->next;
	head->next = head->next->next;
	if (head->next != NULL)
		head->next->prev = head;
	tmp->next = head;
	tmp->prev = head->prev;
	if (head->prev != NULL)
		head->prev->next = tmp;
	if (head->prev == NULL)
		*list = tmp;
	head->prev = tmp;
	print_list(*list);
}