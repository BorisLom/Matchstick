##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## unit tests Makefile
##


SRC=	../src/utils.c

SRC_UT_DIR=	$(realpath .)

SRC_UT=		$(SRC_UT_DIR)/test.c		\
		$(SRC_UT_DIR)/test_get_nbr.c

OBJ=		$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=		-w -Wall -Wextra --coverage

LDFLAGS=	-lcriterion -lgcov

NAME=		test

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS) 

clean:
		rm -f $(OBJ) *.gcda *.gcno

fclean:		clean
		rm -f $(NAME)

re:		fclean all
