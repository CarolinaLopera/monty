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
 * has less of two elements and add is executed.
 *
 * Return: Always void.
 * @line_number: Is a number line
 */
void lesstwoelements(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": can't add, stack too short\n", 29);
	exit(EXIT_FAILURE);
}

/**
 * lesstwoelementsswap - write a error if the list
 * has less of two elements and swap is executed.
 *
 * Return: Always void.
 * @line_number: Is a number line.
 */
void lesstwoelementsswap(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": can't swap, stack too short\n", 30);
	exit(EXIT_FAILURE);
}

/**
 * no_malloc - write a error if malloc fail.
 *
 * Return: Always void.
 */
void no_malloc(void)
{
	write(STDERR_FILENO, "Error: malloc failed\n", 21);
	exit(EXIT_FAILURE);
}

/**
 * lesstwoelementsub - write a error if the list
 * has less of two elements and sub is executed.
 *
 * Return: Always void.
 * @line_number: Is a number line.
 */
void lesstwoelementsub(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": can't sub, stack too short\n", 29);
	exit(EXIT_FAILURE);
}
