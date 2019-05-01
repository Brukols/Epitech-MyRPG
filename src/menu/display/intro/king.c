/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** display king
*/

#include "my_rpg.h"

game_t *move_king(game_t *game, int *stop_king)
{
    game_object_t *king = game->scenes->objs->game_object;

    if (king->rect.left >= 280) {
        king->rect.left = 70;
        game->scenes->objs->clicks->fairy_event = 1;
    }
    if (king->rect.left <= 70)
        game->scenes->objs->clicks->fairy_event = 0;
    if (king->pos.x >= 710) {
        king->pos.x = 800;
        (*stop_king) = 1;
    }
    else
        king->pos.x += 10;
    return (game);
}

void display_king_walk(game_object_t *king, game_t *game)
{
    sfSprite_setPosition(king->sprite, king->pos);
    sfSprite_setTextureRect(king->sprite, king->rect);
    sfSprite_setTexture(king->sprite, king->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, king->sprite, NULL);
}

game_t *king_walk(game_t *game)
{
    game_object_t *king = NULL;
    int king_event = 0;
    background_t *background = game->scenes->objs->background;
    int stop_king = 0;

    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
    game = select_king_walk(game);
    king = game->scenes->objs->game_object;
    king_event = game->scenes->objs->clicks->fairy_event;
    game = move_king(game, &stop_king);
    if (sfClock_getElapsedTime(king->clock).microseconds > 200000 && \
    stop_king != 1) {
        if (king_event == 0)
            king->rect.left += 70;
        else
            king->rect.left -= 70;
        sfClock_restart(king->clock);
    }
    king = game->scenes->objs->game_object;
    display_king_walk(king, game);
    return (game);
}

game_t *move_king_surprise(game_t *game)
{
    game_object_t *king = game->scenes->objs->game_object;

    if (king->rect.left >= 580) {
        king->rect.left = 280;
        game->scenes->objs->clicks->fairy_event = 1;
    }
    if (king->rect.left <= 280)
        game->scenes->objs->clicks->fairy_event = 0;
    return (game);
}
