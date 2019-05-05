/*
** EPITECH PROJECT, 2019
** my_rog
** File description:
** init_buttons_fs_scene
*/

#include "my_rpg.h"

int cut_music(game_t *game)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->prev; button = button->prev);
    for (; button->type != BUTTON_SETTINGS_MUSIC; button = button->next);
    if (button->display_hover == true)
        button->display_hover = false;
    else if (button->display_hover == false)
        button->display_hover = true;
    return SUCCESS;
}

int return_fs_scene(game_t *game)
{
    for (; game->scenes->prev; game->scenes = game->scenes->prev);
    for (; game->scenes->scene != FIRST_SCENE; \
         game->scenes = game->scenes->next);
    return SUCCESS;
}

int return_menu_scene(game_t *game)
{
    for (; game->scenes->prev; game->scenes = game->scenes->prev);
    for (; game->scenes->scene != MENU; \
         game->scenes = game->scenes->next);
    return SUCCESS;
}
