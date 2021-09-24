#include "monty.h"

/**
 * lesstwoelementsdiv - write a error if the list
 * has less of two elements and div is executed.
 *
 * Return: Always void.
 * @line_number: Is a number line.
 */
void lesstwoelementsdiv(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": can't div, stack too short\n", 29);
	exit(EXIT_FAILURE);
}

/**
 * divbyzero - write a error if the top element of
 * the stack is 0 and div is executed.
 *
 * Return: Always void.
 * @line_number: Is a number line.
 */
void divbyzero(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": division by zero\n", 19);
	exit(EXIT_FAILURE);
}

/**
 * lesstwoelementsmul - write a error if the list
 * has less of two elements and mul is executed.
 *
 * Return: Always void.
 * @line_number: Is a number line.
 */
void lesstwoelementsmul(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": can't mul, stack too short\n", 29);
	exit(EXIT_FAILURE);
}

/**
 * asciivalue - write a error if the value is not
 * in the ascii table and pchar is executed.
 *
 * Return: Always void.
 * @line_number: Is a number line.
 */
void asciivalue(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": can't pchar, value out of range\n", 34);
	exit(EXIT_FAILURE);
}

/**
 * stack_emptypchar - write a error if the list is empty
 * and pchar is executed.
 *
 * Return: Always void.
 * @line_number: Is a number line.
 */
void stack_emptypchar(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": can't pchar, stack empty\n", 27);
	exit(EXIT_FAILURE);
}
