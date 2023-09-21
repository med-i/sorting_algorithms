#include "sort.h"

/**
 * swap_nodes - swaps two nodes of doubly linkedlist
 * @list: pointer to pointer to doubly linked list
 * @node: pointer to 1st node
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev, *next;

	prev = node->prev;
	next = node->next;

	prev->next = next;
	if (next)
		next->prev = prev;

	node->prev = prev->prev;
	node->next = prev;

	if (prev->prev)
		prev->prev->next = node;
	else
		*list = node;
	prev->prev = node;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && current->n < prev->n)
		{
			swap_nodes(list, current);
			prev = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
