#include "sort.h"

/**
 * insertion_sort_list - sorts an array of integers in ascending order
 * using the Insertion sort algorithm
 * @list: pointer to head of linked listlsb_release -a
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *tmp = NULL;
	int flag = 0, flag_1 = 0;

	if (!list || !*list || !(*list)->next)
		return;
	head = *list;
	while (head->next != NULL)
	{
		if (head->n > head->next->n)
		{
			tmp = head->next, head->next = head->next->next;
			if (head->next != NULL)
				head->next->prev = head;
			tmp->next = head, tmp->prev = head->prev;
			if (head->prev != NULL)
				head->prev->next = tmp;
			if (head->prev == NULL)
				*list = tmp;
			head->prev = tmp, flag = 1;
			print_list(*list), flag_1 = 0;
			while (tmp->prev != NULL)
			{
				if (tmp->n < tmp->prev->n)
				{
					sort_left(tmp, list);
					flag_1 = 1;
				}
				if (flag_1 == 0)
					tmp = tmp->prev;
				flag_1 = 0;
			}
		}
		if (flag == 0)
			head = head->next;
		flag = 0;
	}
}


/**
 * sort_left - sorts an array of integers
 * using the Insertion sort algorithm
 * @tmp: pointer to head of linked listlsb_release -a
 * @list: list of nodes
 *
 */
void sort_left(listint_t *tmp, listint_t **list)
{
	listint_t *tmp_2 = NULL;

	tmp_2 = tmp->prev, tmp->prev = tmp_2->prev;
	tmp_2->next = tmp->next, tmp->next = tmp_2;
	if (tmp_2->next != NULL)
		tmp_2->next->prev = tmp_2;
	if (tmp_2->prev != NULL)
		tmp_2->prev->next = tmp;
	if (tmp_2->prev == NULL)
		*list = tmp;
	tmp_2->prev = tmp, print_list(*list);
}
