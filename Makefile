##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc -lcsfml-graphics -lcsfml-system -lcsfml-audio -g3

RM	=	rm -f

NAME	=	my_defender

SRCS	=	menu.c	


OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean	:
		$(RM)	$(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
