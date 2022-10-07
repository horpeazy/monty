#include "monty.h"

/**
 * rotl - rotates the stack
 * @stack: pointer to stack
 * @line_number: line number of opcode
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *temp;

	if (!stack || !*stack || !(*stack)->next)
		return;

	(void) line_number;
	node = *stack;
	*stack = node->next;
	(*stack)->prev = NULL;
	temp = *stack;

	while (temp->next)
		temp = temp->next;
	temp->next = node;
	node->prev = temp;
	node->next = NULL;
}

/**
 * rotr - rotates the stack
 * @stack: pointer to stack
 * @line_number: line number of opcode
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
		return;

	(void) line_number;
	temp = *stack;

	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
}
