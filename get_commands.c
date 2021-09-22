#include "monty.h"

/**
 * get_lines - This function open, read the file.
 *
 * Return: A array with each command line.
 * @path: Is a path of the file in argv.
 */
char **get_lines(char *path)
{
	int chars, num_chars = 0, num_lines = 0;
	char **lines = NULL;
	const char *delim = "\n";
	char buf[1024];
	FILE *fd;

	fd = fopen(path, "r");
	if (fd == NULL)
		no_open(path);
	while (chars != EOF)
	{
		chars = getc(fd);
		num_chars++;
		if (chars == '\n')
			num_lines++;
	}
	printf("chars: %i, lines: %i\n", num_chars, num_lines);
	fseek(fd, 0, SEEK_SET);
	fread(buf, num_chars - 2, 1, fd);

	lines = malloc((num_lines + 1) * sizeof(char *));
	lines = token(buf, delim, lines);

	fclose(fd);
	return (lines);
}

/**
 * get_words - This function open, read the file.
 *
 * Return: void.
 * @lines: Is a array of the lines of the file.
 */
void get_words(char **lines)
{
	int num_words, i;
	char **words = NULL;
	const char *delim = " ";
	int flag = 1;

	for (i = 0; lines[i] != NULL; i++)
	{
		num_words = number_words(lines[i], ' ');
		if (num_words == 0)
			continue;
		words = malloc((num_words + 1) * sizeof(char *));
		words = token(lines[i], delim, words);
		if (num_words == 1)
			flag = get_opcode(words[0]);
		if (num_words == 2 && strcmp(words[0], "push") == 0)
			flag = op_push(words[1]);
		if (flag == 1)
			printf("Error command\n");

		/*printf("lines[5]: %s, num_w: %i\n", lines[5], num_words);*/
		free(words);
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
		printf("%s\n", array[j]);
		j++;
		tok = strtok(NULL, delim);
	}
	array[j] = NULL;
	/*printf("j is: %i\n", j);]*/

	return (array);
}
