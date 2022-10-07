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
 * _add - adds the top two elements
 * @stack: stack to add
 * @line_number: line number of operation
 */
void _add(stack_t **stack, unsigned int line_number)
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
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	return;
}

/**
 * _sub - subtracts the top elements
 * @stack: stack to sub
 * @line_number: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	*stack = node->next;
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n - node->n;
	free(node);
}

/**
 * _div - subtracts the top elements
 * @stack: stack to sub
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
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
	(*stack)->n = (*stack)->n / node->n;
	free(node);
}
