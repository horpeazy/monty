#include "monty.h"

/**
 * push - push a element to the stack
 * @stack: pointer to the head of the stack
 * @value: value to push to the stack
 * Return: 0 on success, -1 0n failure
 */
int push(stack_t **stack, unsigned int line_number)
{
	if (add_node(stack, line_number) < 0)
		return (-1);
	return (0);
}
