#include "monty.h"

/**
  * unload_stack - Releases all elements in the stack
  * @stack: head of stack
  * Return: Nothing
  */
void unload_stack(stack_t *stack)
{
	stack_t *temp = NULL;

	if (stack)
	{
		temp = stack;

		while (temp)
		{
			stack = stack->next;
			free(temp);
			temp = stack;
		}
	}
}
