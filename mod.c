#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: The head of the stack
 * @line: The line on which the error occurred
 *
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0;

	if (count_stack(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	a = temp->n;
	b = temp->next->n;
	temp->next->n = b % a;
	*stack = temp->next;
	free(temp);
}
