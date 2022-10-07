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
