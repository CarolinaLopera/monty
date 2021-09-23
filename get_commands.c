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
 * @lines: Is a array of the lines of the file.
 */
char **get_words(char *line, char *path, int nl)
{
	int num_words, len, flag = 0;
	char **words = NULL;
	const char *delim = " ";
	char *command = NULL;
	int num_lines = 0;
	num_lines = number_lines(path, num_lines);

	num_words = number_words(line, ' ');
	if (line[strlen(line)] == '\0')
		flag = 1;

	words = malloc((num_words + 1) * sizeof(char *));
	words = token(line, delim, words);

	/*printf("nl: %i, nt: %i", nl, num_lines);*/
	if (flag == 1 || nl != (num_lines + 1))
		return (words);

	len = strlen(words[num_words - 1]) - 1;
	command = malloc((len + 1) * sizeof(char));

	command = strncpy(command, words[num_words - 1], len);
	words[num_words - 1] = command;

	return (words);
}

/*void list(char **lines)
{
	char **words = NULL;
	int i, num_words;
	stack_t *head = NULL;
	(void)num_words;

	for (i = 0; lines[i] != NULL; i++)
	{
		num_words = number_words(lines[i], ' ');
		words = get_words(lines[i]);
		if (words == NULL)
			continue;

	if (strcmp(words[0], "push") == 0)
		op_push(&head, words, i + 1);
	else
		get_opcode(&head, words[0], i + 1);

		
		num_words = number_words(lines[i], ' ');
		free(words);
	}
}*/

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
