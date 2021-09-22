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
