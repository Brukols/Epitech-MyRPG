/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** king surprise
*/

#include "my_rpg.h"

game_t *display_king_surprise(game_t *game, game_object_t *king, int king_event)
{
    if (sfClock_getElapsedTime(king->clock).microseconds > 200000) {
        if (king_event == 0) {
            king->rect.left += 80;
            king->pos.x += 8;
        }
        if (king->pos.x == 840)
            king->pos.x = 800;
        else if (king_event == 1)
            king->rect.left -= 80;
        sfClock_restart(king->clock);
    }
    king = game->scenes->objs->game_object;
    sfSprite_setPosition(king->sprite, king->pos);
    sfSprite_setTextureRect(king->sprite, king->rect);
    sfSprite_setTexture(king->sprite, king->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, king->sprite, NULL);
    return (game);
}

game_t *king_surprise(game_t *game)
{
    game_object_t *king = NULL;
    int king_event = 0;
    background_t *background = game->scenes->objs->background;

    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
    game = select_king_surprise(game);
    king = game->scenes->objs->game_object;
    king_event = game->scenes->objs->clicks->fairy_event;
    game = move_king_surprise(game);
    game = display_king_surprise(game, king, king_event);
    game = bubble_4(game);
    return (game);
}
