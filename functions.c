#include "monty.h"

/**
 * add_node - adds a node to the front of dlinked_list
 * @head: pointer to the head node
 * @value: value of the node
 * Return: 0 on success, -1 on failure
 */
int add_node(stack_t **head, int value)
{
	stack_t *node, *temp;

	if (!head)
		return (-1);

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = value;

	if (mode == 0)
	{
		node->next = *head;
		node->prev = NULL;
		if (*head != NULL)
			(*head)->prev = node;
		*head = node;
	}
	else
	{
		temp = *head;
		if (!temp)
		{
			node->prev = NULL;
			node->next = NULL;
			*head = node;
			return (1);
		}
		while (temp->next)
			temp = temp->next;
		node->next = NULL;
		node->prev = temp;
		temp->next = node;
	}

	return (1);
}

/**
 * free_stack - frees a dlistint_t list
 *
 * @head: head of the list
 * Return: no return
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
