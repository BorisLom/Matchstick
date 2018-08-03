/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** error handling
*/

#include "matchstick.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//checks of the inputs are valid

int	invalid_inputs(char *av)
{
	if (my_getnbr(av) <= 0) {
		write (2, "Error: invalid inputs\n", 23);
		return (1);
	}
	return (0);
}
