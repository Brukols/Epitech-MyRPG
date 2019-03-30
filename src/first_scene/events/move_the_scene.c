/*
** EPITECH PROJECT, 2019
** move_the_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void move_the_scene(game_t *game, sfKeyCode code)
{
    background_t *bg = game->scenes->objs->background;

    if (code == sfKeyRight)
        bg->move_x = 2;
    if (code == sfKeyLeft)
        bg->move_x = -2;
    if (code == sfKeyDown)
        bg->move_y = 2;
    if (code == sfKeyUp)
        bg->move_y = -2;
}