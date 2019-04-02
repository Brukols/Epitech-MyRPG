/*
** EPITECH PROJECT, 2019
** display all elements
** File description:
** rpg
*/

#include "my_rpg.h"

game_t *display_menu(game_t *game)
{
    background_t *background = game->scenes->objs->background;

    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
    display_play_button(game);
    return (game);
}
