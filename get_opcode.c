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
			ops[iterator].f();
			return (0);
		}
		iterator++;
	}
	return (1);
}

/**
 * op_push -  Prints all the values on the stack
 * starting from the top of the stack.
 * @num: number
 * Return: always 0
 */
void op_push(stack_t *stack_s,char *num)
{
	printf("entro a la funcion push, num: %s\n", num);
	return (0);
}
