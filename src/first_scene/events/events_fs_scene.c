/*
** EPITECH PROJECT, 2019
** events_fs_scene
** File description:
** myrpg
*/

#include "my_rpg.h"

game_object_t *player_params(game_t *game)
{
    game_object_t *player = NULL;

    for (; game->scenes->objs->game_object->prev != NULL; \
         game->scenes->objs->game_object = \
         game->scenes->objs->game_object->prev);
    for (; game->scenes->objs->game_object->type != PLAYER; \
         game->scenes->objs->game_object = game->scenes->objs->game_object->next);
    player = game->scenes->objs->game_object;
    return player;
}

game_t *events_fs_scene(game_t *game)
{
    game_object_t *player = player_params(game);
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtMouseButtonReleased)
            manage_mouse_button_event(game);
        if (event.type == sfEvtKeyPressed) {
            move_the_scene(game, event.key.code, true);
        }
        if (event.type == sfEvtKeyReleased) {
            move_the_scene(game, event.key.code, false);
            interactions(game, event.key.code);
        }
        if (player->pos.x == 900 && player->pos.y <= 480 && \
            player->pos.y >= 400 && event.type == sfEvtKeyPressed && \
            event.key.code == sfKeySpace)
            game->scenes = game->scenes->next;
    }
    return (game);
}
