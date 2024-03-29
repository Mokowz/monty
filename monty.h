#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
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
/**
 * struct vars_s - bariables
 * @val: Value
 * @file: pointer
 * @content: line content
 * @flag: flag
 * Description: contains values
 */
typedef struct vars_s
{
	char *val;
	FILE *file;
	char *content;
	int flag;
} vars_t;
extern vars_t vars;

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void s_pall(stack_t **head, unsigned int count);
void s_pint(stack_t **head, unsigned int count);
void s_pop(stack_t **head, unsigned int count);
void s_swap(stack_t **head, unsigned int count);
void s_add(stack_t **head, unsigned int count);
void s_nop(stack_t **head, unsigned int count);
void s_sub(stack_t **head, unsigned int count);
void s_push(stack_t **head, unsigned int count);
void addnode(stack_t **head, int new);

#endif
