#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: The head of the stack
 * @line: The line on which the error occurred
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *current = *stack, *temp = NULL;

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	temp = current;
	if (current->next)
	{
		current = current->next;
		current->prev = temp->prev;
		*stack = current;
	}
	else
	{
		*stack = NULL;
	}
	free(temp);
}
