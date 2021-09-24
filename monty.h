#ifndef MONTY_H
#define MONTY_H

#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*STRUCTURES*/

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

/*PROTOTYPES*/

void get_lines(char *path);
void get_opcode(stack_t **stack, char **words, unsigned int line_number);
char **token(char *str, const char *delim, char **array);

void op_pint(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **head);
stack_t *op_push(stack_t **head, char **words, int line_number);

int number_words(char *str, char delim);
int number_lines(char *path, int num_lines);
void print_int(int n);
int write_char(char c);

void no_open(char *path);
void no_file(void);
void no_malloc(void);
void no_int(int line_number);
void no_command(int line_number, char **words);
void stack_empty(int line_number);
void stack_emptypop(int line_number);
void lesstwoelements(int line_number);
void lesstwoelementsswap(int line_number);

#endif