##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_rpg
##

NAME	=	my_rpg

SRC	=	src

GENERAL	=	src/general

GENERAL_DISPLAY	=	src/general/display

GENERAL_EVENTS	=	src/general/events

GENERAL_INIT	=	src/general/initialization

FS_SCENE	=	src/first_scene

FS_SCENE_INIT	=	src/first_scene/initialization

FS_SCENE_DISPLAY	=	src/first_scene/display

FS_SCENE_EVENTS	=	src/first_scene/events

SRCS	=	$(GENERAL_DISPLAY)/display_bg.c					\
		$(GENERAL_DISPLAY)/display_player.c				\
		$(GENERAL_DISPLAY)/move_all_the_scene.c				\
		$(GENERAL_DISPLAY)/move_the_scene.c				\
		$(GENERAL_DISPLAY)/sort_game_object.c				\
		$(GENERAL_EVENTS)/player_touch_smth.c				\
		$(GENERAL_EVENTS)/will_touch_smth.c				\
		$(GENERAL_INIT)/init_color.c					\
		$(GENERAL_INIT)/init_house.c					\
		$(GENERAL_INIT)/init_map.c					\
		$(GENERAL_INIT)/init_object_for_map.c				\
		$(GENERAL_INIT)/init_shaft.c					\
		$(GENERAL_INIT)/init_vec2f.c					\
		$(GENERAL_INIT)/str_to_word_array_for_map.c			\
		$(FS_SCENE_DISPLAY)/display_fs_scene.c				\
		$(FS_SCENE_DISPLAY)/display_game_object_fs_scene.c		\
		$(FS_SCENE_EVENTS)/events_fs_scene.c				\
		$(FS_SCENE_INIT)/init_first_scene.c				\
		$(FS_SCENE_INIT)/init_game_object_fs_scene.c			\
		$(FS_SCENE_INIT)/init_player_fs_scene.c				\
		$(FS_SCENE_INIT)/init_scene_object_fs_scene.c			\
		$(FS_SCENE_INIT)/put_chara_in_game_object.c			\
		$(SRC)/init_all_game.c						\
		$(SRC)/launch_game.c						\
		$(SRC)/create_window.c						\
		$(SRC)/main.c

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

debug: CFLAGS += -g

debug: fclean $(OBJS)
	$(MAKE) debug -C lib/my
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(MY) $(GRAPH)
