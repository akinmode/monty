#ifndef MONTY
#define MONTY

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* CONSTANTS */
#define MIN_ARGS 2

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PROTOTYPES: APPLICATIONS */
FILE *openfile(char *filename);
void montyexec(stack_t **stack, char *code,
				char *param, unsigned int nline, char *staque);
void unload_stack(stack_t *stack);
int check_digits(char *str);
int count_stack(stack_t *stack);

/* PROTOTYPES: OPERATIONS */
void (*check_funct(char *s))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int param);
void push_queue(stack_t **stack, unsigned int param);
void pall(stack_t **stack, unsigned int line);
void pint(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);
void add(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);
void sub(stack_t **stack, unsigned int line);
void _div(stack_t **stack, unsigned int line);
void mul(stack_t **stack, unsigned int line);
void mod(stack_t **stack, unsigned int line);
void pchar(stack_t **stack, unsigned int line);
void pstr(stack_t **stack, unsigned int line);
void rotl(stack_t **stack, unsigned int line);
void rotr(stack_t **stack, unsigned int line);

#endif /* MONTY */
