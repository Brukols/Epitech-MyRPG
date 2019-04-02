##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_rpg
##

NAME	=	my_rpg

SRCS	=	launch_game.c			\
		../create_window.c		\
		../init_all_game.c		\
		../main.c			\
		display_buttons.c		\
		display.c			\
		init/init_buttons_play.c	\
		init/init.c			\
		select/start_button.c		\

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L../../lib/my

MY	=	-lmy

GRAPH	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC	=	gcc

MAKE	=	make

RM	=	rm -f

CFLAGS	=	-I../../include -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ../../lib/my
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(MY) $(GRAPH)

clean:
	$(MAKE) clean -C ../../lib/my
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ../../lib/my
	$(RM) $(NAME)

debug: CFLAGS += -g
debug: re
re: fclean all


