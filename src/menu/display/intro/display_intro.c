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
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (mouse_pos.x >= 1700 && mouse_pos.x <= 1850 && \
            mouse_pos.y >= 820 && mouse_pos.y <= 970 && \
            event.mouseButton.type == sfEvtMouseButtonPressed && \
            game->scenes->objs->clicks->user_click < 3)
            game->scenes->objs->clicks->user_click++;
    }
}

void display_skip_button(game_t *game)
{
    game_object_t *skip = game->scenes->objs->game_object;

    for (; skip->prev != NULL; skip = skip->prev);
    if (sfClock_getElapsedTime(skip->clock).microseconds < 600000) {
        for (; skip->type != INTRO_SKIP1; skip = skip->next);
    }
    if (sfClock_getElapsedTime(skip->clock).microseconds > 600000) {
        if (sfClock_getElapsedTime(skip->clock).microseconds > 1200000)
            sfClock_restart(skip->clock);
        for (; skip->type != INTRO_SKIP2; skip = skip->next);
    }
    sfSprite_setPosition(skip->sprite, skip->pos);
    sfSprite_setTexture(skip->sprite, skip->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, skip->sprite, NULL);
}

game_t *earthquake(game_t *game)
{
    background_t *background = game->scenes->objs->background;

    if (sfClock_getElapsedTime( \
        background->clock).microseconds < 600000) {
        background->pos.x -= 20;
    }
    if (sfClock_getElapsedTime(background->clock).microseconds > 600000) {
        if (sfClock_getElapsedTime(background->clock).microseconds > 1200000)
            sfClock_restart(background->clock);
        background->pos.x += 20;
    }
    sfSprite_setPosition(background->sprite, background->pos);
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
    return (game);
}

game_t *display_intro(game_t *game)
{
    game_t *(*fairy_discution[4])() = {bubble_1, bubble_2, bubble_3, earthquake};

    event_intro(game);
    my_put_nbr(game->scenes->objs->clicks->user_click);
    game = fairy_discution[game->scenes->objs->clicks->user_click](game);
    game = display_fairy(game);
    display_skip_button(game);
    return (game);
}
