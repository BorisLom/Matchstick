/*
** EPITECH PROJECT, 2018
** test_putchar
** File description:
** my_putchar test
*/

#include <criterion/criterion.h>

int	my_getnbr(char const *);

Test(my_get_nbr, str_is_normal)
{
	cr_assert_eq(my_getnbr("13"), 13);
}

Test(my_get_nbr, str_is_normal2)
{
	cr_assert_eq(my_getnbr("eeee13"), 13);
}
