/*
** EPITECH PROJECT, 2018
** get_inputs.c
** File description:
** get matchstick inputs
*/

#include "matchstick.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// prints player info
void	player_info(char **values)
{
	my_putstr("Player removed ");
	my_putstr(values[1]);
	my_putstr(" match(es) from line ");
	my_putstr(values[0]);
	my_putchar('\n');
}

// initialise inputs
char	**inputs(char **values, tab_t *array)
{
	values[0] = array->which_line;
	values[1] = array->match_nb;

	return (values);
}

int	get_values(char **values, tab_t *array)
{
	array->match_nb = NULL;
	array->which_line = NULL;

	my_putstr("Line: ");
	array->which_line = get_next_line(0);
	if (array->which_line == NULL)
		return (1);
	if (line_is_correct(array->which_line, array))
		return (96);
	my_putstr("Matches: ");
	array->match_nb = get_next_line(0);
	if (array->match_nb == NULL)
		return (1);
	if (match_is_correct(array->match_nb, array->max_remove, array, \
			     array->which_line))
		return (96);
	if (my_getnbr(array->match_nb) == 0) {
		my_putstr ("Error: you have to remove at least one match\n");
		return (96);
	}
	values = inputs(values, array);
	return (0);
}
