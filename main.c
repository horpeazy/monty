#include "monty.h"

/**
 * main - Entry point
 * @argc: number of arguments passed
 * @argv: array of arguments
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char *argv[])
{
	char *buf;
	int fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty filname\n");
		exit(EXIT_FAILURE);
	}

	buf = malloc(sizeof(char) * 10000);
	if (buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (read(fd, buf, 10000) == -1)
	{
		fprintf(stderr, "Error: Can't read to buffer\n");
		close(fd);
		free(buf);
		exit(EXIT_FAILURE);
	}

	run_code(buf);
	free(buf);
	close(fd);
	return (0);
}

/**
 * run_code - runs the byte code
 * @buf: buffer containing bytecode
 */
void run_code(char *buf)
{
	char *token, *delim;
	unsigned int line, is_push;
	stack_t *stack = NULL;

	is_push = 0;
	line = 1;
	delim = "\n\t\v\r\a ;:";
	token = strtok(buf, delim);

	while (token)
	{
		if (is_push)
		{
			push(&stack, line, token);
			line++;
			is_push = 0;
			token = strtok(NULL, delim);
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			is_push = 1;
			token = strtok(NULL, delim);
			continue;
		}
		else
		{
			if (get_op(token) != NULL)
				get_op(token)(&stack, line);
			else if (token[0] == '#')
				nop(&stack, line);
			else
			{
				free_stack(stack);
				fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, delim);
	}
	free_stack(stack);
}
