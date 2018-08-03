/*
** EPITECH PROJECT, 2018
** matchstick.h
** File description:
** .h
*/

#ifndef _MCHSCK_
#define _MCHSCK_

#ifndef READ_SIZE
#define READ_SIZE	(10)
#endif /*READ_SIZE*/

typedef struct tab_s
{
	char **values;
	char **tab;
	int line_size;
	int line_nb;
	int max_remove;
	int total;
	char *which_line;
	char *match_nb;
}tab_t;

int	rand_a_b(int a, int b);
int	random_line(tab_t *array);
int	random_match(tab_t *array, int line);
void	player_info(char **values);
char	**inputs(char **values, tab_t *array);
int	get_values(char **values, tab_t *array);
int	count_matches(tab_t *array, int line);
int	game_ia(tab_t *array);
int	line_is_correct(char *line, tab_t *array);
int	str_is_num(char *str);
void	my_put_nbr(int nb);
void	draw_roof(int line_nb);
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_getnbr(char const *str);
void	draw_square(int line_nb, tab_t *array);
char	*get_next_line(int fd);
void	remove_match(tab_t *array, int line_nb, int match_nb);
int	game_player(tab_t *array);
int	get_values(char **values, tab_t *array);
int	match_is_correct(char * match_nb, int max_match, tab_t *array, char *nb);
int	invalid_inputs(char *av);

#endif /*MCHSCK*/
