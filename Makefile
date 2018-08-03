##
## EPITECH PROJECT, 2018
## makefile matchstick
## File description:
## makefile
##

SRC	=	src/utils.c		\
		src/main.c		\
		src/get_next_line.c	\
		src/draw_map.c		\
		src/get_inputs.c	\
		src/remove_match.c	\
		src/verifications.c	\
		src/ia.c		\
		src/game.c		\
		src/errors.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS  =	-Wall -Wextra -Iinclude -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
