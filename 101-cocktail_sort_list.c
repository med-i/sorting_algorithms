#include "sort.h"

/**
 * swap_nodes - swap two nodes in a doubly linked list
 * @list: poiter to pointer to the doubly linked list
 * @node1: pointer to the 1st node
 * @node2: pointer to the 2d node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp = NULL;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	temp = node2->next;
	node2->next = node1;
	node1->next = temp;
	node2->prev = node1->prev;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL;
	int swap_move = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swap_move)
	{
		swap_move = 0;
		start = *list;

		while (start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swap_move = 1;
			}
			else
				start = start->next;
		}

		if (!swap_move)
			break;

		swap_move = 0;
		while (start->prev)
		{

			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				print_list(*list);
				swap_move = 1;
			}
			else
				start = start->prev;
		}
	}
}
