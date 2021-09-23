#include "monty.h"

/**
 * get_lines - This function open, read the file.
 *
 * Return: A array with each command line.
 * @path: Is a path of the file in argv.
 */
void get_lines(char *path)
{
	size_t num_chars = 0;
	char *buf = NULL, **words = NULL;
	int num_words = 0, num_lines = 0;
	FILE *fd;
	stack_t *head = NULL;

	fd = fopen(path, "r");
	if (fd == NULL)
		no_open(path);

	while (getline(&buf, &num_chars, fd) != EOF)
	{
		num_lines++;
		num_words = number_words(buf, ' ');
		if (num_words == 0 || buf[0] == '\n')
			continue;
		words = get_words(buf, path, num_lines);
		if (strcmp(words[0], "push") == 0)
			op_push(&head, words, num_lines);
		else
			get_opcode(&head, words[0], num_lines);
	}

	fclose(fd);
}

/**
 * get_words - This function open, read the file.
 *
 * Return: void.
 * @line: Is a array of the lines of the file.
 * @path: Is a path of the file in argv.
 */
char **get_words(char *line, char *path, int nl)
{
	int num_words, len, flag = 0;
	char **words = NULL;
	const char *delim = " ";
	char *command = NULL;
	int num_lines = 0;
	(void)nl, (void)flag;
	num_lines = number_lines(path, num_lines);

	num_words = number_words(line, ' ');
	if (line[(strlen(line) - 1)] != '\n')
		flag = 1;
	/*printf("%s", line);*/

	words = malloc((num_words + 1) * sizeof(char *));
	words = token(line, delim, words);

	if (flag == 1)
		return (words);

	len = strlen(words[num_words - 1]) - 1;
	command = malloc((len + 1) * sizeof(char));

	command = strncpy(command, words[num_words - 1], len);
	words[num_words - 1] = command;
	/*printf("command: %s\n", command);*/

	return (words);
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
		j++;
		tok = strtok(NULL, delim);
	}
	array[j] = NULL;

	return (array);
}
