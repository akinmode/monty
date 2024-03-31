#include "monty.h"

/**
 * openfile - checks if the file is accessible and opens it
 * @filename: file name
 * Return: file handle 'fh'
*/
FILE *openfile(char *filename)
{
	FILE *fh = NULL;

	if (access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	fh = fopen(filename, "r");
	if (!fh)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fh);
}

/**
 * check_funct - checks for the operation from the availlable list
 * @s: operator name
 * Return: VOID
*/
void (*check_funct(char *s))(stack_t **, unsigned int)
{
	instruction_t functs[] = {
		{ "push", push },
		{ "push_queue", push_queue },
		{ "pall", pall },
		{ "pint", pint },
		{ NULL, NULL }
	};
	int i = 0;

	while (functs[i].opcode)
	{
		if (strcmp(s, functs[i].opcode) == 0)
			return (functs[i].f);
		++i;
	}
	return (NULL);
}

/**
  * check_digits - Checks if all characters in a string are digits
  * @str: The string to be evaluated
  * Return: 1 for integer or 0 for others
  */
int check_digits(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '-' && *(str + 1) != '\0')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * count_stack - Counts the number of elements in the stack
 * @stack: The stack to count
 * Return: Number of elements in the stack
 */
int count_stack(stack_t *stack)
{
    int count = 0;
    stack_t *current = stack;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
