#include "monty.h"

/**
 * get_op_function - gets the op fucntions
 * @name: name of the fucntion
 * Return: a pointer to the fucntion
 */
int get_op(char *name)
{
	int i = 0;

	instruction_t ops[] = {
		"push": _push,
		NULL: NULL
	}

	while (ops[i].opcode != NULL)
	{
		if (strcmp(name, ops[i].opcode) == 0)
			return ops[i].f;
		i++
	}

	return (NULL);
}
