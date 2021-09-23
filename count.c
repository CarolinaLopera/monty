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
	/*num_lines = number_words(buf, '\n');*/

	fclose(fd);
	return (num_lines);
}

/*char **copyn(char **cpy, char **lines)
{
	int i = 0;

	while (*lines != NULL)
	{
		printf("%s\n", *lines);
		cpy[i] = strncpy(cpy[i], lines[i], strlen(lines[i]) - 1);
		i++;
		lines++;
	}
	return (cpy);
}*/

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
