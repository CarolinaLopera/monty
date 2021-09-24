#include "monty.h"

/**
 * op_sub - Subtracts the top element of the stack
 * from the second top element of the stack.
 *
 * Return: Always void.
 * @stack: Is a pointer to header of the list.
 * @line_number: Is a current number line.
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head = (*stack);
	int sub = 0;
	int contador = 0;

	while ((*stack) != NULL)
	{
		(*stack) = (*stack)->next;
		contador++;
	}
	(*stack) = head;
	if (contador < 2)
		lesstwoelementsub(line_number);

	sub = (*stack)->next->n - (*stack)->n;
	op_pop(stack, line_number);
	(*stack)->n = sub;
}

/**
 * op_div - Divides the second top element of the stack
 * by the top element of the stack.
 *
 * Return: Always void.
 * @stack: Is a pointer to header of the list.
 * @line_number: Is a current number line.
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *head = (*stack);
	int div = 0;
	int contador = 0;

	while ((*stack) != NULL)
	{
		(*stack) = (*stack)->next;
		contador++;
	}
	(*stack) = head;
	if (contador < 2)
		lesstwoelementsdiv(line_number);
	else
	{
		if ((*stack)->n == 0)
		{
			divbyzero(line_number);
		}
		else
		{
			div = ((*stack)->next->n / (*stack)->n);
			op_pop(stack, line_number);
			(*stack)->n = div;
		}
	}
}

/**
 * op_mul - Multiplies the second top element of the stack
 * with the top element of the stack.
 *
 * Return: Always void.
 * @stack: Is a pointer to header of the list.
 * @line_number: Is a current number line.
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head = (*stack);
	int mul = 0;
	int contador = 0;

	while ((*stack) != NULL)
	{
		(*stack) = (*stack)->next;
		contador++;
	}
	(*stack) = head;
	if (contador < 2)
		lesstwoelementsmul(line_number);
	else
	{
		mul = (*stack)->n * (*stack)->next->n;
		op_pop(stack, line_number);
		(*stack)->n = mul;
	}
}

/**
 * op_pchar - prints the char at the top of the stack.
 *
 * Return: Always void.
 * @stack: Is a pointer to header of the list.
 * @line_number: Is a current number line.
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *head = (*stack);

	if (head != NULL)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
			printf("%c\n", (*stack)->n);
		else
			asciivalue(line_number);
	}
	else
		stack_emptypchar(line_number);
}
