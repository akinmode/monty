#include "monty.h"

/**
  * push - Adds a new node at the beginning of the stack
  * @stack: head of the stack
  * @param: param value
  * Return: VOID
  */
void push(stack_t **stack, unsigned int param)
{
	stack_t *inode = NULL;

	inode = malloc(sizeof(stack_t));
	if (inode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	inode->n = atoi(param);
	if (*stack)
	{
		inode->next = *stack;
		inode->prev = (*stack)->prev;
		(*stack)->prev = inode;
		*stack = inode;
		return;
	}

	inode->next = *stack;
	inode->prev = NULL;
	*stack = inode;
}

/**
  * push_queue - Adds a new node at the end of the stack
  * @stack: head of the stack
  * @param: value to adds on the stack
  * Return: VOID
  */
void push_queue(stack_t **stack, unsigned int param)
{
	stack_t *current = NULL, *inode = NULL;

	inode = malloc(sizeof(stack_t));
	if (inode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	inode->n = atoi(param);
	if (*stack)
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;

		inode->next = NULL;
		inode->prev = current;
		current->next = inode;
		return;
	}

	inode->next = *stack;
	inode->prev = NULL;
	*stack = inode;
}
