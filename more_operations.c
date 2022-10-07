#include "monty.h"

/**
 * swap - swaps the first two elements of a stack
 * @stack: stack to swap
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = (*stack)->next;
	(*stack)->next = node->next;
	node->next->prev = *stack;
	node->next = *stack;
	node->prev = NULL;
	*stack = node;
}

/**
 * add - adds the top two elements
 * @stack: stack to add
 * @line_number: line number of operation
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	*stack = node->next;
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n + node->n;
	free(node);
}

/**
 * nop - doesn't do anything
 * @stack: stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *node = *stack;

	(void) line_number;
	if (i == 1)
		printf("%d\n", node->n);
}
