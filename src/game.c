/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game player and ia
*/

#include "matchstick.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	game_player(tab_t *array)
{
	char **values = malloc(sizeof(char *) * 2);
	int verif = 0;

	verif = get_values(values, array);
	while (1) {
		if (verif == 96)
			return (1);
		if (verif == 1)
			return (96);
		player_info(values);
		remove_match(array, my_getnbr(values[0]), my_getnbr(values[1]));
		array->total = array->total - (my_getnbr(values[1]));
		if (array->total <= 0) {
			return (4);
		}
		free(values);
		return (0);
	}
}

int	game_ia(tab_t *array)
{
	int line = random_line(array);
	int match = random_match(array, line);

	my_putstr("AI's turn...\n");
	my_putstr("AI removed ");
	my_put_nbr(match);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putchar('\n');
	remove_match(array, line, match);
	array->total = array->total - match;

	return (2);
}
