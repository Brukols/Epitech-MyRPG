##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_rpg
##

NAME	=	my_rpg

SRCS	=	src/launch_game.c			\
		src/create_window.c		\
		src/init_all_game.c			\
		src/init_color.c			\
		src/init_vec2f.c			\
		src/first_scene/display/display_bg_fs_scene.c			\
		src/first_scene/display/display_fs_scene.c				\
		src/first_scene/initialization/init_first_scene.c		\
		src/first_scene/initialization/init_scene_object_fs_scene.c	\
		src/first_scene/events/events_fs_scene.c			\
		src/first_scene/events/move_the_scene.c				\
		src/main.c

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L./lib/my

MY	=	-lmy

GRAPH	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC	=	gcc

MAKE	=	make

RM	=	rm -f

CFLAGS	=	-I./include -W -Wall -Wextra

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
