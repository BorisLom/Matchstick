/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** gl
*/

#include "matchstick.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;
	while (i != n) {
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

int	my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i += 1;
	return (i);
}

char	*my_realloc(char *line, int i, char *buff, int *cursor)
{
	int lenght = 0;
	char *new_line = NULL;

	if (line != 0)
		lenght = my_strlen(line);
	if ((new_line = malloc(sizeof(char) * (lenght + 1 + i))) == NULL)
		return (NULL);
	if (line != 0)
		my_strncpy(new_line, line, i);
	else
		my_strncpy(new_line, "", i);
	my_strncpy(new_line + lenght, buff + *cursor, i);
	if (line == 0)
		free(line);
	*cursor += i + 1 ;
	return (new_line);
}

char	*get_next_line(int fd)
{
	int i = 0;
	char *line = 0;
	static char buff[READ_SIZE];
	static int buff_value;
	static int cursor = 0;

	while (1) {
		if (cursor >= buff_value) {
			i = 0;
			cursor = 0;
			buff_value = read(fd, buff, READ_SIZE);
			if (buff_value == 0)
				return (line);
			if (buff_value == -1)
				return (NULL);
		}
		if (buff[cursor + i] == '\n') {
			line = my_realloc(line, i, buff, &cursor);
			return (line);
		}
		if (cursor + i == buff_value - 1) {
			line = my_realloc(line, i, buff, &cursor);
		}
		i += 1;
	}
	return (0);
}
