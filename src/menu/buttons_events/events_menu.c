/*
** EPITECH PROJECT, 2019
** events_menu
** File description:
** my_rpg
*/

#include "my_rpg.h"

void manage_buttons_menu(game_t *game)
{
    sfVector2i tmp_mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse = init_vec2f(tmp_mouse.x, tmp_mouse.y);

    touch_a_button(game, mouse);
}

void events_menu(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.mouseButton.type == sfEvtMouseButtonPressed)
            manage_buttons_menu(game);
    }
}