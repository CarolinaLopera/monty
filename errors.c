#include "monty.h"

/**
 * no_open - write a error if the file can't open
 * @path: the rout of the monty file
 */
void no_open(char *path)
{
	write(STDERR_FILENO, "Error: Can't open file <", 24);
	write(STDERR_FILENO, path, strlen(path));
	write(STDERR_FILENO, ">\n", 2);
	exit(EXIT_FAILURE);
}
