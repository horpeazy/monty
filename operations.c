#include "monty.h"

/**
 * is_number - checks if the toke is a number
 * @token: token to validate
 * Return: 1 if true, 0 otherwise
 */
int is_number(char *token)
{
	char *n = token;

	if (*n == '-')
		n++;
	while (*n)
	{
		if (!isdigit(*n))
			return (0);
		n++;
	}
	return (1);
}

/**
 * push - push a element to the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the op
 * @n: value to push to the stack
 * Return: 0 on success, -1 0n failure
 */
int push(stack_t **stack, unsigned int line_number, char *n)
{
	if (!stack)
		return (-1);
	if (!is_number(n))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (add_node(stack, atoi(n)) == -1)
	{
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * pall - prints all elements in a stack
 * @stack: stack to print
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!stack || !*stack)
		return;

	(void) line_number;
	node = *stack;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * pint - prints the top of the stack
 * @stack: stack to print
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
