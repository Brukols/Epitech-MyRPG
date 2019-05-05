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

void re_init_movement(game_t *game)
{
    background_t *bg = game->scenes->objs->background;
    player_t *player = game->scenes->objs->player;

    bg->move_x = 0;
    bg->move_y = 0;
    player->move_x = 0;
    player->move_y = 0;
    player->game_object->move_x = 0;
    player->game_object->move_y = 0;
}

void pause_the_game(game_t *game)
{
    bool quit = false;
    sfTexture *texture = sfTexture_createFromFile(\
    "ressources/sprites/pause.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = init_vec2f(500, 70);

    re_init_movement(game);
    if (!sprite || !texture)
        return;
    pause_all_musics(game->scenes->musics);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfRenderWindow_display(game->window);
    while (quit == false) {
        event_pause(game, &quit);
    }
    play_all_musics(game->scenes->musics);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}