#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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

typedef struct token_s
{
	char *token_1;
	char *token_2;
}token_t;

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
        int (*f)(stack_t **stack, unsigned int line_number);
}instruction_t;

int line_check(char *line, char delim[]);
int file_check(FILE *fd);
void parse_line(char *line, char delim[], token_t *tokens, unsigned int line_number, char *dup_line);
int s_push(stack_t **stack, unsigned int line_number, token_t **tokens);
void free_stack(stack_t **stack);
int _atoi(char *);
int monty_pall(stack_t **stack, unsigned int line_number);
int exec_line(stack_t **stack, unsigned int line_number, token_t **tokens);
/**int q_push(&stack, line_number, tokens);*/
#endif
