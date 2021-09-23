#include "monty.h"

/**
 * number_words - count the words in a string
 * @str: string
 * @delim: is a delimitador for string
 * Return: number of words
 */
int number_words(char *str, char delim)
{
	int len = strlen(str);
	int i, w = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == delim && str[i + 1] != delim && (i + 1 != len))
			w++;
	}

	if (str[0] != delim)
		w++;
	return (w);
}

/**
 * number_lines - count the lines in a string
 *
 * Return: Number of lines.
 * @path: Is a path of the file to read
 * @num_lines: is a variable int.
 */
int number_lines(char *path, int num_lines)
{
	char buf[1024];
	int num_chars = 0, chars;
	FILE *fd;

	fd = fopen(path, "r");
	if (fd == NULL)
		no_open(path);

	chars = getc(fd);
	while (chars != EOF)
	{
		chars = getc(fd);
		num_chars++;
		if (chars == '\n')
			num_lines++;
	}
	fseek(fd, 0, SEEK_SET);
	fread(buf, num_chars, 1, fd);

	fclose(fd);
	return (num_lines);
}

/**
 * print_int - Function to print numbers int in console.
 *
 * Return: Always void.
 * @n: is an integer that takes to print.
 */
void print_int(int n)
{
	if (n / 10 != 0)
	{
		print_int(n / 10);
	}
	write_char((n % 10) + '0');
}

/**
 * write_char - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_char(char c)
{
	return (write(2, &c, 1));
}
