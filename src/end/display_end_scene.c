/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** end
*/

#include "my_rpg.h"

void poll_event_produced(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (user_want_close_the_window(event) == true)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace)
            sfRenderWindow_close(game->window);
    }
}

void produced_by(game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile(\
"ressources/sprites/end/scene_fin.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = init_vec2f(0, 0);

    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfRenderWindow_display(game->window);
    while (sfRenderWindow_isOpen(game->window))
        poll_event_produced(game);
}

void poll_event_end_game(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (user_want_close_the_window(event) == true)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace)
            produced_by(game);
    }
}

void end_game(game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile(\
"ressources/sprites/end/scene_fin1.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = init_vec2f(0, 0);

    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfRenderWindow_display(game->window);
    while (sfRenderWindow_isOpen(game->window))
        poll_event_end_game(game);
}
