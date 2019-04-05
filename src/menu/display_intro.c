/*
** EPITECH PROJECT, 2019
** intro display
** File description:
** rpg
*/

#include "my_rpg.h"

void event_intro(game_t *game)
{
    game_object_t *fairy = game->scenes->objs->game_object;
    int user_clicks = game->scenes->objs->clicks->user_click;
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

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

game_t *display_intro(game_t *game)
{
    background_t *background = game->scenes->objs->background;

    event_intro(game);
    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
    game = display_fairy(game);
    return (game);
}
