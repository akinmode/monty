#include "monty.h"

/**
  * rotl - Rotates the stack to the top
  * @stack: head of the stack
  * @line: line number on which the error occurred
  * Return: VOID
  */
void rotl(stack_t **stack, unsigned int line)
{
	stack_t *curr = *stack;
	unsigned int temp = 0;
	(void) line;

	if (curr && curr->next)
	{
		while (curr->next != NULL)
		{
			temp = curr->n;
			curr->n = curr->next->n;
			curr->next->n = temp;
			curr = curr->next;
		}
	}
}
