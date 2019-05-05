/*
** EPITECH PROJECT, 2019
** events_fs_scene
** File description:
** myrpg
*/

#include "my_rpg.h"

bool user_want_close_the_window(sfEvent event)
{
    if (event.type == sfEvtClosed)
        return (true);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        return (true);
    return (false);
}

bool user_pause_the_game(sfEvent event)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace)
        return (true);
    return (false);
}

game_t *events_fs_scene(game_t *game)
{
    int verif;
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (user_want_close_the_window(event) == true)
            sfRenderWindow_close(game->window);
        if (user_pause_the_game(event) == true)
            pause_the_game(game);
        if (event.type == sfEvtMouseButtonReleased)
            manage_mouse_button_event(game);
        if (event.type == sfEvtKeyPressed)
            move_the_scene(game, event.key.code, true);
        if (event.type == sfEvtKeyReleased) {
            move_the_scene(game, event.key.code, false);
            verif = interactions(game, event.key.code);
        }
        if (verif == GO_TO_FIGHT_SCENE)
            return (game);
    }
    return (game);
}
