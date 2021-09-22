#include "monty.h"

/**
 * get_opcode - compare the opcode with corresponding function.
 * @s: Opcode.
 * Return: the opcode.
 */

int *get_opcode(const char *s)
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
		if (*(ops[iterator].op) == *s)
		{
			return (ops[iterator].f);
		}
		iterator++;
	}
	return (NULL);
}
