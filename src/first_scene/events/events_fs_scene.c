/*
** EPITECH PROJECT, 2019
** events_fs_scene
** File description:
** myrpg
*/

#include "my_rpg.h"

game_t *events_fs_scene(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyPressed) {
            move_the_scene(game, event.key.code, true);
        }
        if (event.type == sfEvtKeyReleased) {
            move_the_scene(game, event.key.code, false);
            interactions(game, event.key.code);
        }
    }
    return (game);
}