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
	int num, i, flag = 0;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		free(words);
		free_stack(head);
		no_malloc();
	}
	if (words[1] == NULL)
	{
		free(words), free(new_node);
		free_stack(head);
		no_int(line_number);
	}

	for (i = 0; words[1][i] != '\0'; i++)
	{
		if (words[1][0] == '-' && flag == 0)
		{
			flag = 1;
			continue;
		}
		if (isdigit(words[1][i]) == 0)
		{
			free(words), free(new_node);
			free_stack(head);
			no_int(line_number);
		}
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

/**
 * free_stack - Frees all nodes of a list.
 *
 * Return: Always void.
 * @head: pointer to the first node.
 */
void free_stack(stack_t **head)
{
	stack_t *aux = NULL;

	while (*head != NULL)
	{
		aux = (*head)->next;
		free(*head);
		*head = aux;
	}
}

/**
 * get_opcode - compare the opcode with corresponding function.
 * @words: Is array with the commands.
 * @stack: Is a header of the list.
 * @line_number: Is a number line.
 * Return: Always void.
 */
void get_opcode(stack_t **stack, char **words, unsigned int line_number)
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
		if (strcmp(ops[iterator].opcode, words[0]) == 0)
		{
			ops[iterator].f(stack, line_number);
			return;
		}
		iterator++;
	}
	free_stack(stack);
	no_command(line_number, words);
}
