/*
** EPITECH PROJECT, 2018
** ia.c
** File description:
** ia file
*/

#include "matchstick.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int	rand_a_b(int a, int b)
{
	return (rand() % (b-a) + a);
}

//randomize the line
int	random_line(tab_t *array)
{
	int line = rand_a_b(1, array->line_nb);

	while (count_matches(array, line) == 0) {
		line = rand_a_b(1, array->line_nb + 1);
	}
	return (line);
}

//randomize the number of matches
int	random_match(tab_t *array, int line)
{
	int match = rand_a_b(0, array->max_remove);
	int al = match % 4;

	while (count_matches(array, line) < match || al != 1) {
		match = rand_a_b(1, array->max_remove + 1);
		al = match % 4;
		}
	return (match);
}
