/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** earthquake and interrogation point
*/

#include "my_rpg.h"

void interrogation(game_t *game)
{
    game_object_t *interrogation = NULL;

    if (game->scenes->objs->clicks->user_click != 3)
        return;
    game = select_interrogation(game);
    interrogation = game->scenes->objs->game_object;
    if (sfClock_getElapsedTime(interrogation->clock).microseconds > 3009000) {
        sfSprite_setPosition(interrogation->sprite, interrogation->pos);
        sfSprite_setTexture(interrogation->sprite, \
        interrogation->texture, sfFalse);
        sfRenderWindow_drawSprite(game->window, interrogation->sprite, NULL);
    }
}

void red_bubble(game_t *game)
{
    game_object_t *bubble = NULL;

    if (game->scenes->objs->clicks->user_click != 4)
        return;
    game = select_red_bubble(game);
    bubble = game->scenes->objs->game_object;
    sfSprite_setPosition(bubble->sprite, bubble->pos);
    sfSprite_setTexture(bubble->sprite, bubble->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, bubble->sprite, NULL);
}

game_t *earthquake(game_t *game)
{
    background_t *background = game->scenes->objs->background;

    if (sfClock_getElapsedTime(background->clock).microseconds < 100000) {
        background->pos.y -= 2.3;
    }
    if (sfClock_getElapsedTime(background->clock).microseconds > 100000) {
        if (sfClock_getElapsedTime(background->clock).microseconds > 200000)
            sfClock_restart(background->clock);
        background->pos.y += 1.5;
    }
    sfSprite_setPosition(background->sprite, background->pos);
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
    interrogation(game);
    red_bubble(game);
    return (game);
}
