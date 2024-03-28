#include "monty.h"

/**
 * montyexec - execute monty codes line by line
 * @stack: head of stack
 * @code: operation to execute
 * @param: input value
 * @nline: code line read from input file
 * @staque: stack or queue
 * Return: VOID
*/
void montyexec(stack_t **stack, char *code,
				char *param, unsigned int nline, char *staque)
{
	void (*code_ops)(stack_t **, unsigned int);

	code_ops = check_funct(code);
	if (code_ops)
	{
		if (strcmp(code, "push") == 0)
		{
			if (check_digits(param) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", nline);
				exit(EXIT_FAILURE);
			}
			else
			{
				if (strcmp(staque, "stack") == 0)
				{
					code_ops(stack, atoi(param));
				}
				else
				{
					code_ops = check_funct("push_queue");
					code_ops(stack, atoi(param));
				}
			}
		}
		else
		{
			code_ops(stack, nline);
		}
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", nline, code);
		exit(EXIT_FAILURE);
	}
}
