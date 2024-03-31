#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: The head of the stack
 * @line: The line on which the error occurred
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0;

	if (count_stack(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	a = temp->n;
	b = temp->next->n;
	temp->next->n = b * a;
	*stack = temp->next;
	free(temp);
}
