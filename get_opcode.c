#include "monty.h"

/**
 * get_opcode - compare the opcode with corresponding function.
 * @s: Opcode.
 * Return: the opcode.
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
 * op_push -  Prints all the values on the stack
 * starting from the top of the stack.
 */
stack_t *op_push(stack_t **head, char **words, int line_number)
{
	int num;
	stack_t *new_node = malloc(sizeof(stack_t));

	/*printf("entro a la funcion push\n");*/
	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (words[1] == NULL)
		no_int(line_number);

	num = atoi(words[1]);
	if (num == 0)
		no_int(line_number);

	new_node->n = num;
	new_node->next = (*head);
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;

	/*if (new_node->prev != NULL)
		printf("prev: %i\n", new_node->prev->n);
	if (new_node->next != NULL)
		printf("next: %i\n", new_node->next->n);
	printf("new: %i\n", new_node->n);
	printf("salió de la funcion push\n");*/

	return (new_node);
}

void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}