/*
** EPITECH PROJECT, 2018
** map.c
** File description:
** map drawing related functions
*/

#include "matchstick.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//draws the roof of the map
void	draw_roof(int line_nb)
{
	int nb = line_nb + line_nb + 1;
	int i = 0;
	char *tab = malloc(sizeof(char) * nb);

	while (i < nb) {
		tab[i] = '*';
		my_putchar(tab[i]);
		i += 1;
	}
	my_putchar('\n');
	free(tab);
}

//draws the sides of the map
int	draw_side(int line_nb, int size_square, tab_t *array)
{
	int i = 0;

	while (i < array->line_size) {
		if (line_nb == 0 || line_nb == size_square + 1)
			array->tab[line_nb][i] = '*';
		else if (i == 0 || i == size_square * 2)
			array->tab[line_nb][i] = '*';
		else if (i > size_square - line_nb && i < size_square + line_nb)
			array->tab[line_nb][i] = '|';
		else
			array->tab[line_nb][i] = ' ';
		i += 1;
	}
	array->tab[line_nb][i] = '\n';
	array->tab[line_nb][i + 1] = '\0';
	my_putstr(array->tab[line_nb]);
	return (0);
}

//draws the lines of the map (the matche)
int	draw_line(int line_nb, tab_t *array)
{
	int i = 1;

	array->tab = malloc(sizeof(char *) * (line_nb + 2));
		while (i <= line_nb) {
			array->tab[i] = malloc(sizeof(char) * line_nb * 2 + 3);
			draw_side(i, line_nb, array);
			i++;
		}
	return (0);
}

//draws the entire map
void	draw_square(int line_nb, tab_t *array)
{
	draw_roof(line_nb);
	draw_line(line_nb, array);
	draw_roof(line_nb);
	my_putchar('\n');
}
