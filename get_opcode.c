#include "monty.h"

/**
 * get_opcode - compare the opcode with corresponding function.
 * @s: Opcode.
 * Return: the opcode.
 */
int get_opcode(stack_t **stack, char *s, unsigned int line_number)
{
	int iterator = 0;

	instruction_t ops[] = {
		{"pint", op_pint},
		{"pall", op_pall},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{NULL, NULL}};

	while (ops[iterator].opcode != NULL)
	{
		if (strcmp(ops[iterator].opcode, s) == 0)
		{
			ops[iterator].f(stack, line_number);
			return (0);
		}
		iterator++;
	}
	return (1);
}

/**
 * op_push -  Prints all the values on the stack
 * starting from the top of the stack.
 */
stack_t *op_push(stack_t **head, char **words, int line_number)
{
	int num;
	stack_t *new_node = malloc(sizeof(stack_t));

	printf("entro a la funcion push\n");
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

	return (new_node);
}
