/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick
*/

#include "matchstick.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//initialise values
tab_t	*init(char *lines, char *matches)
{
	tab_t *array = malloc(sizeof(*array));

	array->line_nb = my_getnbr(lines);
	array->max_remove = my_getnbr(matches);
	array->line_size = array->line_nb * 2 + 1;
	array->total = array->line_nb * array->line_nb;

	return (array);
}

int	full_game(char *lines, char *matches)
{
	tab_t *array = init(lines, matches);
	int verif = 0;

	draw_square(array->line_nb, array);
	my_putstr("Your turn:\n");
	while (1) {
		if (verif == 2)
			my_putstr("Your turn:\n");
		verif = game_player(array);
		if (verif == 1)
			continue;
		if (verif == 96)
			return (0);
		if (array->total <= 0 && verif == 4)
			return (2);
		verif = game_ia(array);
		if (array->total <= 0 && verif == 2)
			return (3);
	}
}

int	main(int ac, char **av)
{
	int win = 0;

	if (ac < 3) {
		write (2, "Error :expected 2 arguments\n", 29);
		return (84);
	}
	if (invalid_inputs(av[1]) == 1 || invalid_inputs(av[2]) == 1)
		return (84);
	win = full_game (av[1], av[2]);
	if (win == 0)
		return (0);
	if (win == 2) {
		my_putstr("You lost, too bad...\n");
		return (2);
	}
	if (win == 3) {
		my_putstr("I lost... snif... but I'll get you next time!!\n");
		return (1);
	}
}
