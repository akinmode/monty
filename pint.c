#include "monty.h"

/**
 * pint - Prints the value at the top of the stack followed by a new line.
 * @stack: The head of the stack
 * @line: The line on which the error occurred
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
