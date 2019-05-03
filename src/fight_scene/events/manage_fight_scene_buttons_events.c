/*
** EPITECH PROJECT, 2019
** manage_fight_scene_buttons.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void manage_fight_scene_buttons_events(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse = init_vec2f(mouse_pos.x, mouse_pos.y);

    touch_a_button(game, mouse);
}
