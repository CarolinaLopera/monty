#include "monty.h"

/**
 * get_opcode - compare the opcode with corresponding function.
 * @s: Opcode.
 * Return: the opcode.
 */
int get_opcode(const char *s)
{
	op_t ops[] = {
		{"pint", op_pint},
		{"pall", op_pall},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{NULL, NULL}};
	int iterator = 0;

	while (ops[iterator].op != NULL)
	{
		if (strcmp(ops[iterator].op, s) == 0)
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
 */
int op_push(char *num)
{
	printf("entro a la funcion push, num: %s\n", num);
	return (0);
}
