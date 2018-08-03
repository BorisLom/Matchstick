/*
** EPITECH PROJECT, 2018
** verifications
** File description:
** verify things
*/

#include "matchstick.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	count_matches(tab_t *array, int line)
{
	int i = 0;
	int j = 0;

	while (i < array->line_size) {
		if (array->tab[line][i] == '|')
			j++;
		i++;
	}
	return (j);
	}

// checks if the matches are a correct (number not too high, and enough matches on the line)
int	match_is_correct(char *match_nb, int max_match, tab_t *str, char *nb)
{
	int current_match = count_matches(str, my_getnbr(nb));

	if (my_getnbr(match_nb) > max_match) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(max_match);
		my_putstr(" matches per turn\n");
		return (1);
	}
	else if (str_is_num(match_nb)) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (1);
	}
	else {
		if (current_match < my_getnbr(match_nb)) {
			my_putstr("Error: not enough matches on this line\n");
			return (1);
		}
	}
	return (0);
}

// checks if the line number (in the arguments) is correct
int	line_is_correct(char *line, tab_t *array)
{
	if (str_is_num(line)) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (1);
	}
	else if (my_getnbr(line) > array->line_nb || my_getnbr(line) == 0) {
		my_putstr ("Error: this line is out of range\n");
		return (1);
	}
	return (0);
}
