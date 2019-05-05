/*
** EPITECH PROJECT, 2019
** fight_events.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int fight_events(game_t *game)
{
    sfEvent event;
    int callback = 0;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.mouseButton.type == sfEvtMouseButtonPressed)
            callback = manage_fight_scene_buttons_events(game);
        if (callback == ERROR)
            return (ERROR);
        else if (callback == 1)
            return (1);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->window);
    }
    return (0);
}
