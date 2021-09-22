#include "monty.h"

/**
 * no_open - write a error if the file can't open
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
 */
void no_file(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 19);
	exit(EXIT_FAILURE);
}
