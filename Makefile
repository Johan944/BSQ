##
## Makefile for  in /home/ganem-_j/rendu/CPE_2015_BSQ
##
## Made by johan ganem--brunet
## Login   <ganem-_j@epitech.net>
##
## Started on  Fri Dec 18 11:45:50 2015 johan ganem--brunet
## Last update Mon Dec 21 22:57:36 2015 johan ganem--brunet
##

SRCS		=		functions.c \
				bsq.c \
				main.c \
				init.c \
				error.c \
				bonus/bonus.c \
				my_puterr.c \

NAME		=		bsq

OBJ		=		$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) -g3

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
