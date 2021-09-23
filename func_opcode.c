#include "monty.h"

/**
 * op_pint - Prints the value at the top of the stack,
 * followed by a new line.
 *
 * Return: Always void.
 * @stack: Is a pointer to header of the list.
 * @line_number: Is a current number line.
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = (*stack);

	if (head != NULL)
		printf("%i\n", head->n);
	else
		stack_empty(line_number);
}

/**
 * op_pall -  Prints all the values on the stack
 * starting from the top of the stack.
 *
 * Return: Always void.
 * @stack: Is a pointer to header of the list.
 * @line_number: Is a current number line.
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *head = (*stack);
	(void)line_number;

	while (*stack != NULL)
	{
		printf("%i\n", (*stack)->n);
		(*stack) = (*stack)->next;
		i++;
	}
	(*stack) = head;
}

/**
 * op_pop - Removes the top element of the stack.
 *
 * Return: Always void.
 * @stack: Is a pointer to header of the list.
 * @line_number: Is a current number line.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack);

	if ((*stack) != NULL)
	{
		(*stack) = (*stack)->next;
		free(temp);
		temp = (*stack);
	}
	else
		stack_emptypop(line_number);
}

/**
 * op_swap - Swap The top two elements of the stack.
 *
 * Return: Always void.
 * @stack: Is a pointer to header of the list.
 * @line_number: Is a current number line.
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = (*stack);
	stack_t *temp = (*stack);
	int contador = 0;

	while ((*stack) != NULL)
	{
		(*stack) = (*stack)->next;
		contador++;
	}
	(*stack) = head;
	if (contador < 2)
		lesstwoelementsswap(line_number);
	else
	{
		(*stack) = (*stack)->next;
		temp->prev = (*stack);
		temp->next = (*stack)->next;
		(*stack)->next = temp;
	}
}

/**
 * op_add - Add the top two elements of the stack.
 *
 * Return: Always void.
 * @stack: Is a pointer to header of the list.
 * @line_number: Is a current number line.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = (*stack);
	int sum = 0;
	int contador = 0; 

	while ((*stack) != NULL)
	{
		(*stack) = (*stack)->next;
		contador++;
	}
	(*stack) = head;
	if (contador < 2)
		lesstwoelements(line_number);
	else
	{
		sum += (*stack)->n;
		op_pop(stack, line_number);
		sum += (*stack)->n;
		(*stack)->n = sum;
	}
}
