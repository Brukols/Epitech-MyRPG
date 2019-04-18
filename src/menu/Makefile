##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_rpg
##

NAME	=	my_rpg

SRCS	=	launch_game.c				\
		../create_window.c			\
		../init_all_game.c			\
		../main.c				\
		buttons_events/bottoms_buttons.c	\
		buttons_events/play_buttons_event.c	\
		display/display.c			\
		display/intro/display_intro.c		\
		display/intro/fairy.c			\
		display/intro/bubbles.c			\
		display/display_buttons.c		\
		init/init.c				\
		init/buttons/init_buttons_play.c	\
		init/buttons/init_bottoms_buttons.c	\
		init/intro/bubbles.c			\
		init/intro/init_intro.c			\
		init/intro/skip.c			\
		init/tittle_and_background.c		\
		select/start_button.c			\
		select/bubbles.c			\
		init/intro/polypoppy.c			\
		init/intro/fairy_events.c		\
		display/intro/king.c			\
		display/intro/earthquake.c		\
		display/intro/king_surprise.c		\

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


