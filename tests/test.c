/*
** EPITECH PROJECT, 2018
** test
** File description:
** my_putstr tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void	my_putstr(char *);
void	my_putchar(char);

void	redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(my_putstr, str_is_normal, .init = redirect_all_std)
{
	my_putstr("pouet");
	cr_assert_stdout_eq_str("pouet");
}

Test(my_putstr, str_is_wrong, .init = redirect_all_std)
{
	my_putstr(NULL);
	cr_assert_stdout_eq_str("pouett");
}
