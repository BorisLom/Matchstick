/*
** EPITECH PROJECT, 2018
** remove_match.c
** File description:
** remove matches
*/

#include "matchstick.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// remove the matches and updates the map
void	remove_match(tab_t *array, int line_nb, int match_nb)
{
	int x = 1;
	int i = array->line_size;
	int j = 0;

	while (array->tab[line_nb][i] != '|')
		i--;
	while (j < match_nb && i != 0) {
		array->tab[line_nb][i] = ' ';
		i--;
		j++;
	}
	draw_roof(array->line_nb);
	while (x < array->line_nb + 1) {
		my_putstr(array->tab[x]);
		x++;
	}
	draw_roof(array->line_nb);
	my_putchar('\n');
}
