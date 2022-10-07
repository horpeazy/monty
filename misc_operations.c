#include "monty.h"

/**
 * _mul - multiplies the top elements of stack
 * @stack: stack to multiply
 * @line_number: line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	*stack = node->next;
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n * node->n;
	free(node);
}

/**
 * _mod - subtracts the top elements
 * @stack: stack to sub
 * @line_number: line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	*stack = node->next;
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n % node->n;
	free(node);
}
