/*
** EPITECH PROJECT, 2019
** pause_the_game
** File description:
** my_rpg
*/

#include "my_rpg.h"

void event_pause(game_t *game, bool *quit)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed \
        && event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(game->window);
            *quit = true;
        }
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace)
            *quit = true;
    }
}

void pause_the_game(game_t *game)
{
    bool quit = false;

    pause_all_musics(game->scenes->musics);
    while (quit == false)
        event_pause(game, &quit);
    play_all_musics(game->scenes->musics);
}