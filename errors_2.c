#include "monty.h"

/**
 * stack_emptypop - write a error if the list is empty
 * and try to delete a node.
 *
 * Return: Always void.
 * @line_number: Is a number line
 */
void stack_emptypop(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": can't pop an empty stack\n", 27);
	exit(EXIT_FAILURE);
}

/**
 * lesstwoelements - write a error if the list
 * has less of two elements.
 *
 * Return: Always void.
 * @line_number: Is a number line
 */
void lesstwoelements(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": can't add, stack too short\n", 28);
	exit(EXIT_FAILURE);
}

/**
 * lesstwoelementsswap - write a error if the list
 * has less of two elements.
 *
 * Return: Always void.
 */
void lesstwoelementsswap(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": can't swap, stack too short\n", 29);
	exit(EXIT_FAILURE);
}
