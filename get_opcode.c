#include "monty.h"

/**
 * op_push -  Prints all the values on the stack
 * starting from the top of the stack.
 *
 * Return: A pointer to new node.
 * @head: Is a header of the list.
 * @line_number: Is a number line.
 * @words: Is a array of the words with the commands.
 */
stack_t *op_push(stack_t **head, char **words, int line_number)
{
	int num, i;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		no_malloc();

	if (words[1] == NULL)
		no_int(line_number);

	for (i = 0; words[1][i] != '\0'; i++)
	{
		if (isdigit(words[1][i]) == 0)
			no_int(line_number);
	}
	num = atoi(words[1]);

	new_node->n = num;
	new_node->next = (*head);
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;

	return (new_node);
}

/**
 * get_opcode - compare the opcode with corresponding function.
 * @s: Is the command.
 * @stack: Is a header of the list.
 * @line_number: Is a number line.
 * Return: Always void.
 */
void get_opcode(stack_t **stack, char *s, unsigned int line_number)
{
	int iterator = 0;

	instruction_t ops[] = {
		{"pint", op_pint},
		{"pall", op_pall},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"pchar", op_pchar},
		{NULL, NULL}};

	while (ops[iterator].opcode != NULL)
	{
		if (strcmp(ops[iterator].opcode, s) == 0)
		{
			ops[iterator].f(stack, line_number);
			return;
		}
		iterator++;
	}
	no_command(line_number, s);
}

/**
 * op_nop - This function doesn’t do anything.
 *
 * Return: Always void.
 * @stack: Is a pointer to header of the list.
 * @line_number: Is a current number line.
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack, (void)line_number;
}
