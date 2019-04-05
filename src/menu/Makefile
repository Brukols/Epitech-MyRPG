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
		buttons_events/display_buttons.c	\
		buttons_events/bottoms_buttons.c	\
		buttons_events/play_buttons_event.c	\
		display.c				\
		display_intro.c				\
		init/init_intro.c			\
		init/init_buttons_play.c		\
		init/init_bottoms_buttons.c		\
		init/tittle_and_background.c		\
		init/init.c				\
		select/start_button.c			\

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


