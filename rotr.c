#include "monty.h"

/**
  * rotr - Rotates the stack to the bottom
  * @stack: head of the stack
  * @line: line number on which the error occurred
  * Return: Nothing
  */
void rotr(stack_t **stack, unsigned int line)
{
	stack_t *last = NULL;
	(void) line;

	if (*stack && (*stack)->next)
	{
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		last->prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}
