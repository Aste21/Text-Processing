#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "rand_malloc.h"
#include <stdbool.h>

int get_length_of_line(const char *line)
{
	if (line == NULL)
	{
		return 0;
	}
	int size = 0;
	while (line[size] != 10 && line[size])
	{
		size += 1;
	}
	return size;
}

void print_line_backwards(char *line)
{
	size_t size_of_line = get_length_of_line(line);
	for (int i = size_of_line; i >= 0; i--)
	{
		if (line[i] == '\n')
		{
			i--;
		}
			if (line[i] == ' ')
			{
				int j = i + 1;
				while (line[j] != ' ' && line[j] != '\n' && j<size_of_line)
				{
					printf("%c", line[j]);
					j++;
				}
				printf(" ");
			}
			if (i == 0)
			{
				int j = i;
				while (line[j] != ' ' && line[j] != '\n' && j<size_of_line)
				{
					printf("%c", line[j]);
					j++;
				}
			}
		
	}
	printf("\n");
}

char *get_line(bool *is_fail)
{
	char *line = NULL;
	int character_input;
	size_t size = 0;
	size_t bufsize = 0;
	while ((character_input = getchar()) != EOF)
	{
		if (size >= bufsize)
		{
			char *newbuf;
			if (bufsize == 0)
			{
				bufsize = 2;
			}
			else if (bufsize <= ((size_t)-1) / 2)
			{
				bufsize = 2 * size;
			}
			else
			{
				*is_fail = true;
				free(line);
				return NULL;
			}
			newbuf = realloc(line, bufsize);
			if (newbuf == NULL)
			{
				*is_fail = true;
				free(line);
				return NULL;
			}
			line = newbuf;
		}
		line[size++] = character_input;

		if (character_input == '\n')
		{
			break;
		}
	}
	if ((character_input == EOF) && size == 0)
	{
		return NULL;
	}
	if (size >= bufsize)
	{
		char *newbuf;
		if (size < (size_t)-1)
		{
			bufsize = size + 1;
		}
		else
		{
			*is_fail = true;
			free(line);
			return NULL;
		}

		newbuf = realloc(line, bufsize);
		if (newbuf == NULL)
		{
			*is_fail = true;
			free(line);
			return NULL;
		}
		line = newbuf;
	}
	line[size++] = '\0';
	return line;
}

void **read_lines()
{
	bool is_fail = false;
	char **lines = NULL;
	char *line;
	size_t bufsize_line = 0;
	size_t line_count = 0;
	while ((line = get_line(&is_fail)))
	{
		if (line_count >= bufsize_line)
		{
			char **newbuf;
			if (bufsize_line == 0)
			{
				bufsize_line = 2;
			}
			else if (bufsize_line <= ((size_t)-1) / 2 / sizeof(char *))
			{
				bufsize_line = 2 * line_count;
			}
			else
			{
				is_fail = true;
				goto ERROR;
			}
			newbuf = realloc(lines, bufsize_line * sizeof(char *));
			if (newbuf == NULL)
			{
				is_fail = true;
				goto ERROR;
			}
			lines = newbuf;
		}
		lines[line_count++] = line;
	}
	if (is_fail)
	{
		goto ERROR;
	}
	if(!is_fail)
	{
		printf("\n\nNormal output:\n");
		for (int i = 0; i < line_count; i++)
		{
			printf("%s", lines[i]);
		}
		printf("\n\nBackwards output :\n");
		for (int i = line_count - 1; i >= 0; i--)
		{
			print_line_backwards(lines[i]);
			free(lines[i]);
		}
		free(lines);
		return 0;
	}
ERROR:
	for (int i = line_count-1; i >= 0; i--)
	{
		free(lines[i]);
	}
	free(lines);
	free(line);
	exit(1);
}

int main(int argc, char *argv[])
{
	read_lines();
	return 0;
}