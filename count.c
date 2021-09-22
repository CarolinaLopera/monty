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
