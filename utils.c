/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** basic functions
*/

#include "matchstick.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	my_put_nbr(int nb)
{
	if (nb > 9) {
		my_put_nbr(nb/10);
	}
	my_putchar((nb%10) + '0');
}

int	str_is_num(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9') {
			return (1);
		}
		else if (str[i + 1] == ' ')
			return (0);
		i++;
	}
	return (0);
}

int	my_getnbr(char const *str)
{
	int i = 0;
	int result = 0;
	if (str == NULL)
		return (84);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
		result = result * 10 + str[i] - 48;
		i += 1;
	}
	if (str[0] == '-') {
		result = - result;
	}
	return (result);
}


void	my_putchar(char c)
{
	write (1, &c, 1);
}

void	my_putstr(char *str)
{
	while (*str != '\0') {
		my_putchar(*str);
		str++;
	}
}
