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

GENERAL_INIT_ITEMS	=	src/general/initialization/items

FS_SCENE	=	src/first_scene

FS_SCENE_INIT	=	src/first_scene/initialization

FS_SCENE_DISPLAY	=	src/first_scene/display

FS_SCENE_EVENTS	=	src/first_scene/events

HOUSE_PLAYER		=	src/first_scene/initialization/houses/house_player

HOUSE_ZORO		=	src/first_scene/initialization/houses/zoro_house

MENU		=	src/menu

INIT_HOUSES	=	src/first_scene/initialization/houses

MENU_SELECT	=	src/menu/select

MENU_EVENTS	=	src/menu/buttons_events

MENU_DISPLAY	=	src/menu/display

MENU_DISPLAY_INTRO	=	src/menu/display/intro

MENU_INIT	=	src/menu/init

MENU_INIT_BUTTONS	=	src/menu/init/buttons

MENU_INIT_INTRO	=	src/menu/init/intro

SETTINGS	=	src/settings

FIGHT_SCENE = src/fight_scene

END_GAME	=	src/end

SRCS	=	$(GENERAL_DISPLAY)/display_bg.c					\
		$(GENERAL_DISPLAY)/display_player.c				\
		$(GENERAL_DISPLAY)/move_all_the_scene.c				\
		$(GENERAL_DISPLAY)/move_the_scene.c				\
		$(GENERAL_DISPLAY)/sort_game_object.c				\
		$(GENERAL_DISPLAY)/display_buttons.c				\
		$(GENERAL_DISPLAY)/display_dialog.c				\
		$(GENERAL_DISPLAY)/display_inventory.c				\
		$(GENERAL_DISPLAY)/display_quests.c				\
		$(GENERAL_DISPLAY)/display_msg_in_box.c				\
		$(GENERAL_DISPLAY)/display_game_object.c			\
		$(GENERAL_DISPLAY)/my_put_pixel.c				\
		$(GENERAL_DISPLAY)/display_particle.c				\
		$(GENERAL_DISPLAY)/animation_shaft.c				\
		$(GENERAL_DISPLAY)/my_draw_square.c				\
		$(GENERAL_DISPLAY)/display_wind.c				\
		$(GENERAL_DISPLAY)/display_leaf.c				\
		$(GENERAL_DISPLAY)/move_player_in_house.c			\
		$(GENERAL_DISPLAY)/gameplay.c					\
		$(GENERAL_DISPLAY)/music_voice.c				\
		$(GENERAL_DISPLAY)/display_status_menu.c			\
		$(GENERAL_DISPLAY)/display_player_stats.c			\
		$(GENERAL_EVENTS)/player_touch_smth.c				\
		$(GENERAL_EVENTS)/will_touch_smth.c				\
		$(GENERAL_EVENTS)/manage_all_music.c				\
		$(GENERAL_EVENTS)/change_dialog.c				\
		$(GENERAL_EVENTS)/interactions.c				\
		$(GENERAL_EVENTS)/button_is_clicked.c				\
		$(GENERAL_EVENTS)/manage_mouse_button_event.c			\
		$(GENERAL_EVENTS)/go_to_fight_scene.c				\
		$(GENERAL_EVENTS)/interaction_with_chest.c			\
		$(GENERAL_EVENTS)/player_have_the_key.c				\
		$(GENERAL_EVENTS)/there_is_an_interaction.c			\
		$(GENERAL_EVENTS)/change_quest.c				\
		$(GENERAL_EVENTS)/add_item.c					\
		$(GENERAL_EVENTS)/remove_item.c					\
		$(GENERAL_EVENTS)/player_touch_chest.c				\
		$(GENERAL_EVENTS)/delete_an_item.c				\
		$(GENERAL_EVENTS)/move_on_the_house.c				\
		$(GENERAL_EVENTS)/touch_walls_house.c				\
		$(GENERAL_EVENTS)/interaction_with_other_chest.c		\
		$(GENERAL_EVENTS)/stop_music_scene.c				\
		$(GENERAL_EVENTS)/music_play.c					\
		$(GENERAL_EVENTS)/pause_the_game.c					\
		$(GENERAL_EVENTS)/actualize_stats_player.c					\
		$(GENERAL_EVENTS)/change_dialog2.c					\
		$(GENERAL_INIT)/init_color.c					\
		$(GENERAL_INIT)/init_house.c					\
		$(GENERAL_INIT)/init_map.c					\
		$(GENERAL_INIT)/init_object_for_map.c				\
		$(GENERAL_INIT)/init_shaft.c					\
		$(GENERAL_INIT)/init_cone.c					\
		$(GENERAL_INIT)/init_vec2f.c					\
		$(GENERAL_INIT)/str_to_word_array_for_map.c			\
		$(GENERAL_INIT)/init_pnj.c					\
		$(GENERAL_INIT)/init_discuss.c					\
		$(GENERAL_INIT)/init_box_dialog.c				\
		$(GENERAL_INIT)/init_text_box.c					\
		$(GENERAL_INIT)/init_rocks.c					\
		$(GENERAL_INIT)/init_chests.c					\
		$(GENERAL_INIT)/put_chara_in_game_object.c			\
		$(GENERAL_INIT)/init_player.c					\
		$(GENERAL_INIT)/init_game_object_scene.c			\
		$(GENERAL_INIT)/init_inventory.c				\
		$(GENERAL_INIT)/init_items.c					\
		$(GENERAL_INIT)/init_what_texture.c				\
		$(GENERAL_INIT)/init_quests.c					\
		$(GENERAL_INIT)/init_particle.c					\
		$(GENERAL_INIT)/init_all_particle.c				\
		$(GENERAL_INIT)/init_wind_particle.c				\
		$(GENERAL_INIT)/init_status_menu.c				\
		$(GENERAL_INIT)/init_button_status_menu.c			\
		$(GENERAL_INIT)/init_stats.c					\
		$(GENERAL_INIT)/init_player_stats.c				\
		$(GENERAL_INIT)/init_special_voice.c				\
		$(GENERAL_INIT_ITEMS)/create_amulet.c				\
		$(GENERAL_INIT_ITEMS)/create_banana.c				\
		$(GENERAL_INIT_ITEMS)/create_chaos.c				\
		$(GENERAL_INIT_ITEMS)/create_cloak.c				\
		$(GENERAL_INIT_ITEMS)/create_helmet.c				\
		$(GENERAL_INIT_ITEMS)/create_katana.c				\
		$(GENERAL_INIT_ITEMS)/create_potion.c				\
		$(GENERAL_INIT_ITEMS)/create_ring.c				\
		$(GENERAL_INIT_ITEMS)/create_speelbook.c			\
		$(GENERAL_INIT_ITEMS)/create_star.c				\
		$(GENERAL_INIT_ITEMS)/create_sword.c				\
		$(GENERAL_INIT_ITEMS)/create_vulcan.c				\
		$(GENERAL_INIT_ITEMS)/create_wand.c				\
		$(GENERAL_INIT_ITEMS)/create_key.c				\
		$(SETTINGS)/init_button.c			\
		$(MENU_EVENTS)/events_menu.c			\
		$(SETTINGS)/display_settings.c			\
		$(SETTINGS)/init_settings_buttons.c		\
		$(SETTINGS)/init_scene_settings.c		\
		$(SETTINGS)/swap_scenes.c			\
		$(MENU_DISPLAY)/display.c			\
		$(MENU_DISPLAY)/display_buttons_menu.c		\
		$(MENU_DISPLAY_INTRO)/display_intro.c		\
		$(MENU_DISPLAY_INTRO)/fairy.c			\
		$(MENU_DISPLAY_INTRO)/bubbles.c			\
		$(MENU_DISPLAY_INTRO)/king.c			\
		$(MENU_DISPLAY_INTRO)/earthquake.c		\
		$(MENU_DISPLAY_INTRO)/king_surprise.c		\
		$(MENU_INIT)/init.c				\
		$(MENU_INIT)/tittle_and_background.c		\
		$(MENU_INIT_BUTTONS)/init_buttons_play.c	\
		$(MENU_INIT_BUTTONS)/init_bottoms_buttons.c	\
		$(MENU_INIT_INTRO)/bubbles.c			\
		$(MENU_INIT_INTRO)/bubbles_2.c			\
		$(MENU_INIT_INTRO)/init_intro.c			\
		$(MENU_INIT_INTRO)/skip.c			\
		$(MENU_INIT_INTRO)/polypoppy.c			\
		$(MENU_INIT_INTRO)/fairy_events.c		\
		$(MENU_SELECT)/bubbles.c			\
		$(MENU_SELECT)/bubbles_2.c			\
		$(FS_SCENE_DISPLAY)/display_fs_scene.c				\
		$(FS_SCENE_DISPLAY)/display_player_house.c			\
		$(FS_SCENE_DISPLAY)/display_texts_fs_scene.c			\
		$(FS_SCENE_DISPLAY)/display_texts_house_player.c		\
		$(FS_SCENE_DISPLAY)/move_zoro.c					\
		$(FS_SCENE_DISPLAY)/move_zoro_gameplay.c			\
		$(FS_SCENE_DISPLAY)/move_the_master.c				\
		$(FS_SCENE_DISPLAY)/manage_story.c				\
		$(FS_SCENE_DISPLAY)/play_musics_fs_scene.c			\
		$(FS_SCENE_EVENTS)/events_fs_scene.c				\
		$(FS_SCENE_EVENTS)/unlock_smth_fs_scene.c			\
		$(FS_SCENE_EVENTS)/go_in_another_scene_fs_scene.c		\
		$(FS_SCENE_EVENTS)/go_back_to_first_scene.c			\
		$(FS_SCENE_INIT)/init_first_scene.c				\
		$(FS_SCENE_INIT)/init_scene_object_fs_scene.c			\
		$(FS_SCENE_INIT)/init_texts_fs_scene.c				\
		$(FS_SCENE_INIT)/init_buttons_fs_scene.c			\
		$(FS_SCENE_INIT)/init_musics_fs_scene.c				\
		$(FS_SCENE_INIT)/init_musics_player_house.c			\
		$(HOUSE_PLAYER)/init_player_house.c				\
		$(HOUSE_PLAYER)/init_plant.c					\
		$(HOUSE_PLAYER)/init_bed.c					\
		$(HOUSE_PLAYER)/init_scene_object_player_house.c		\
		$(HOUSE_PLAYER)/init_object_player_house.c			\
		$(HOUSE_PLAYER)/init_buttons_house_player.c			\
		$(HOUSE_PLAYER)/init_texts_player_house.c			\
		$(HOUSE_ZORO)/init_object.c					\
		$(HOUSE_ZORO)/init_zoro_house.c					\
		$(FS_SCENE_DISPLAY)/zoro_house.c				\
		$(FIGHT_SCENE)/init/init_fight_scene.c				\
		$(FIGHT_SCENE)/init/init_enemies.c				\
		$(FIGHT_SCENE)/init/init_fight_scene_buttons.c			\
		$(FIGHT_SCENE)/init/init_fight_scene_music.c			\
		$(FIGHT_SCENE)/init/init_fight_scene_text.c			\
		$(FIGHT_SCENE)/init/init_fight_scene_objs.c			\
		$(FIGHT_SCENE)/init/init_fight_scene_game_objs.c		\
		$(FIGHT_SCENE)/manage_fight_scene.c				\
		$(FIGHT_SCENE)/get_player_stats.c				\
		$(FIGHT_SCENE)/display_fight_scene.c				\
		$(FIGHT_SCENE)/wait_n_seconds.c					\
		$(FIGHT_SCENE)/actions/player_basic_attack.c			\
		$(FIGHT_SCENE)/actions/player_magic_attack.c			\
		$(FIGHT_SCENE)/actions/enemy_attack.c				\
		$(FIGHT_SCENE)/actions/escape_fight_scene.c			\
		$(FIGHT_SCENE)/actions/rand_action.c				\
		$(FIGHT_SCENE)/actions/calcul_attack.c				\
		$(FIGHT_SCENE)/actions/display_info.c				\
		$(FIGHT_SCENE)/events/fight_events.c				\
		$(FIGHT_SCENE)/events/manage_fight_scene_buttons_events.c	\
		$(END_GAME)/display_end_scene.c					\
		$(SRC)/make_connection_between_scenes.c				\
		$(SRC)/destroy_musics.c						\
		$(SRC)/init_all_game.c						\
		$(SRC)/launch_game.c						\
		$(SRC)/create_window.c						\
		$(SRC)/main.c

OBJS	=	$(SRCS:.c=.o)

LDFLAGS	=	-L lib/my -lmy

FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC	=	gcc

MAKE	=	make

CFLAGS	=	-I./include -W -Wall -Wextra

all	: 	$(NAME)

$(NAME)	: 	$(OBJS)
		make -C lib/my
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(FLAGS)

clean	:
		make clean -C lib/my
		$(RM) $(OBJS)

fclean	: 	clean
		make fclean -C lib/my
		$(RM) $(NAME)

re	: 	fclean all

debug	: 	CFLAGS += -g
debug	: 	re

.PHONY	:	all clean fclean re debug
