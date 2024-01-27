#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node_1: A pointer to the first node to swap.
 * @node_2: The second node to swap.
 */
void swap_nodes(listint_t **head, listint_t **node_1, listint_t *node_2)
{
	(*node_1)->next = node_2->next;
	if (node_2->next != NULL)
		node_2->next->prev = *node_1;
	node_2->prev = (*node_1)->prev;
	node_2->next = *node_1;
	if ((*node_1)->prev != NULL)
		(*node_1)->prev->next = node_2;
	else
		*head = node_2;
	(*node_1)->prev = node_2;
	*node_1 = node_2->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iteration, *node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iteration = (*list)->next; iteration != NULL; iteration = temp)
	{
		temp = iteration->next;
		node = iteration->prev;
		while (node != NULL && iteration->n < node->n)
		{
			swap_nodes(list, &node, iteration);
			print_list((const listint_t *)*list);
		}
	}
}
