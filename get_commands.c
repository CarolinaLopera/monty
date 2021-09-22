#include "monty.h"

/**
 * get_lines - This function open, read the file.
 *
 * Return: A array with each command line.
 * @path: Is a path of the file in argv.
 */
char **get_lines(char *path)
{
	int num_chars = 0, num_lines = 0, chars = 0;
	char **lines = NULL;
	const char *delim = "\n";
	char buf[1024];
	FILE *fd;
	(void)chars;

	fd = fopen(path, "r");
	if (fd == NULL)
		no_open(path);
	chars = getc(fd);
	while (chars != EOF)
	{
		chars = getc(fd);
		num_chars++;
	}
	fseek(fd, 0, SEEK_SET);
	fread(buf, num_chars, 1, fd);
	/*printf("%s", buf);*/

	num_lines = number_words(buf, '\n');
	printf("chars: %i, lines: %i\n", num_chars, num_lines);

	lines = malloc((num_lines + 2) * sizeof(char *));
	lines = token(buf, delim, lines);

	fclose(fd);
	return (lines);
	/*getline(&buf, num_chars, fd);
	printf("%s", buf);*/
}

/**
 * get_words - This function open, read the file.
 *
 * Return: void.
 * @lines: Is a array of the lines of the file.
 */
char **get_words(char *line)
{
	int num_words;
	char **words = NULL;
	const char *delim = " ";

	num_words = number_words(line, ' ');
	words = malloc((num_words + 1) * sizeof(char *));
	words = token(line, delim, words);
	/*printf("num_w is: %i\n", num_words);*/

	/*if (num_words == 0)
	{
		free(words);
		return (NULL);
	}*/
	return (words);

}

void list(char **lines)
{
	char **words = NULL;
	int i, num_words;
	stack_t *head = NULL;
	(void)num_words;

	for (i = 0; lines[i] != NULL; i++)
	{
		num_words = number_words(lines[i], ' ');
		words = get_words(lines[i]);
		/*if (words == NULL)
			continue;*/

		if (strcmp(words[0], "push") == 0)
			op_push(&head, words, i + 1);
		else
			get_opcode(&head, words[0], i + 1);

		/*
		num_words = number_words(lines[i], ' ');
		free(words);*/
	}
}

/**
 * token - This function split a string for lines.
 *
 * Return: Always a array of pointers.
 * @str: Is the file .m to split.
 * @delim: Is a delimiter to split the string.
 * @array: Is a matrix to save each line.
 */
char **token(char *str, const char *delim, char **array)
{
	char *tok = NULL;
	int j = 0;

	tok = strtok(str, delim);
	while (tok != NULL)
	{
		array[j] = tok;
		/*printf("%s\n", array[j]);*/
		j++;
		tok = strtok(NULL, delim);
	}
	array[j] = NULL;
	/*printf("j is: %i\n", j);]*/

	return (array);
}
