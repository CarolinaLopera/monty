#include "monty.h"

/**
 * no_open - write a error if the file can't open
 *
 * Return: Always void.
 * @path: the rout of the monty file
 */
void no_open(char *path)
{
	write(STDERR_FILENO, "Error: Can't open file ", 23);
	write(STDERR_FILENO, path, strlen(path));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

/**
 * no_file - write a error if argv != 2
 *
 * Return: Always void.
 */
void no_file(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 18);
	exit(EXIT_FAILURE);
}

/**
 * no_int - write a error if there is no argument given to push
 * or if it is is not a integer.
 *
 * Return: Always void.
 * @line_number: Is a number line 
 */
void no_int(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": usage: push integer\n", 22);
	exit(EXIT_FAILURE);
}

/**
 * no_command - write a error if no find command.
 *
 * Return: Always void.
 * @line_number: Is a number line
 * @s: string with the instruction bad
 */
void no_command(int line_number, char *s)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": unknown instruction ", 22);
	write(STDERR_FILENO, s, strlen(s));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

/**
 * stack_empty - write a error if the list is empty
 * and pint is executed.
 *
 * Return: Always void.
 * @line_number: Is a number line
 */
void stack_empty(int line_number)
{
	write(STDERR_FILENO, "L", 1);
	print_int(line_number);
	write(STDERR_FILENO, ": can't pint, stack empty\n", 26);
	exit(EXIT_FAILURE);
}
