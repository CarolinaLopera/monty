#include "monty.h"

/**
 * main - This function main.
 *
 * Return: Always int.
 * @argv: Are the arguments give to the program.
 * @argc: Is the number of argumnets.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		no_file();

	get_lines(argv[argc - 1]);

	return (0);
}
