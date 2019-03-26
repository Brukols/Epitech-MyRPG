##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_rpg
##

NAME	=	my_rpg

SRCS	=	src/launch_game.c		\
		main.c

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L./lib/my

MY	=	-lmy

GRAPH	=	-lcsfml-graphics -lcsfml-window -lscfml-system -lcsfml-audio

CC	=	gcc

MAKE	=	make

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(MY) $(GRAPH)

clean:
	$(MAKE) clean -C lib/my
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C lib/my
	$(RM) $(NAME)

re: fclean all
