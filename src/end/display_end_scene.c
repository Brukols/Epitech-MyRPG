/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** end
*/

#include "my_rpg.h"

void produced_by(game_t *game)
{
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
    sfVector2f pos;

    texture = sfTecture_createFromFile("\
ressources/sprites/end/scene_fin.png", NULL);
    sprite = sfSprite_create();
    pos = init_vec2f(0, 0);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (user_want_close_the_window(event) == true)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyReleased && event.key.code    \
            == sfKeySpace)
            sfRenderWindow_close(game->window);
    }
}

void end_game(game_t *game)
{
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
    sfVector2f pos;

    texture = sfTecture_createFromFile("\
ressources/sprites/end/scene_fin1.png", NULL);
    sprite = sfSprite_create();
    pos = init_vec2f(0, 0);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (user_want_close_the_window(event) == true)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyReleased && event.key.code    \
            == sfKeySpace)
            produced_by(game);
    }
}
