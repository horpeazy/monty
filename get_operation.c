#include "monty.h"

/**
 * get_op - gets the op fucntions
 * @name: name of the function
 * Return: a pointer to the fucntion
 */
void (*get_op(char *name))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t ops[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{"nop", nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(name, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
