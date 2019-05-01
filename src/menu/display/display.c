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
    sfRenderWindow_drawText(game->window, game->scenes->texts->text, NULL);
    display_buttons_menu(game);
    events_menu(game);
    return (game);
}
