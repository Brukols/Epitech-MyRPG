/*
** EPITECH PROJECT, 2019
** display fairy
** File description:
** rpg
*/

#include "my_rpg.h"

game_t *move_fairy(game_t *game)
{
    game_object_t *fairy = game->scenes->objs->game_object;

    if (fairy->rect.left >= 480) {
        fairy->rect.left = 0;
        game->scenes->objs->clicks->fairy_event = 1;
    }
    if (fairy->rect.left <= 0)
        game->scenes->objs->clicks->fairy_event = 0;
    return (game);
}

game_t *display_fairy(game_t *game)
{
    game = select_fairy(game);
    game_object_t *fairy = game->scenes->objs->game_object;
    int fairy_event = game->scenes->objs->clicks->fairy_event;

    if (sfClock_getElapsedTime(fairy->clock).microseconds > 200000) {
        if (fairy_event == 0)
            fairy->rect.left += 160;
        else
            fairy->rect.left -= 160;
        sfClock_restart(fairy->clock);
    }
    game = move_fairy(game);
    sfSprite_setPosition(fairy->sprite, fairy->pos);
    sfSprite_setTextureRect(fairy->sprite, fairy->rect);
    sfSprite_setTexture(fairy->sprite, fairy->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, fairy->sprite, NULL);
    return (game);
}
