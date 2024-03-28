#include "monty.h"

char *isStaque(char *code);

/**
  * main - The Monty Interpreter entry point
  * @argc: The args number
  * @argv: The args passed to the interpreter
  * Return: Always zero
  */
int main(int argc, char *argv[])
{
	stack_t *top = NULL;
	FILE *fh = NULL;
	size_t n = 0;
	char *rline = NULL, *code = NULL, *param = NULL, *staque = NULL;
	unsigned int nline = 1;

	if (argc < MIN_ARGS)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	else
	{
		fh = openfile(argv[1]);
		while (getline(&rline, &n, fh) != -1)
		{
			code = strtok(rline, "\t\n ");
			if (code && code[0] != '#')
			{
				if (strcmp(code, "queue") == 0 || strcmp(code, "stack") == 0)
				{
					staque = isStaque(code);
					++nline;
					continue;
				}
				if (staque == NULL)
					staque = "stack";
				param = strtok(NULL, "\t\n ");
				montyexec(&top, code, param, nline, staque);
			}
			++nline;
		} fclose(fh);
	} free(rline), unload_stack(top);
	return (0);
}

/**
 * isStaque - direct for queue or stack
 * @code: code status
 * Return: direction
*/
char *isStaque(char *code)
{
	if (strcmp(code, "queue") == 0)
	{
		return ("queue");
	}
	else
	{
		return ("stack");
	}
}
