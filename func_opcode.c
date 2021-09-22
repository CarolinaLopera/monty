#include "monty.h"

/**
 * op_pint - Prints the value at the top of the stack,
 * followed by a new line.
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	printf("entro a la funcion pint\n");

	if (stack != NULL)
		printf("%i\n", (*stack)->n);
}

/**
 * op_pall -  Prints all the values on the stack
 * starting from the top of the stack.
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	size_t i = 0;
	(void)line_number;

	/*printf("entro a la funcion pall\n");*/

	while (*stack != NULL)
	{
		printf("%i\n", (*stack)->n);
		(*stack) = (*stack)->next;
		i++;
	}
	/*printf("salió a la funcion pall\n");*/
}

/**
 * op_pop - Removes the top element of the stack.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	printf("entro a la funcion pop\n");
}

/**
 * op_swap - Swap The top two elements of the stack.
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	printf("entro a la funcion swap\n");
}

/**
 * op_add - Add the top two elements of the stack.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	printf("entro a la funcion add\n");
}
