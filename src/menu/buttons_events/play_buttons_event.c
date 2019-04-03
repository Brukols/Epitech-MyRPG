/*
** EPITECH PROJECT, 2019
** events play button
** File description:
** my rpg
*/

#include "my_rpg.h"

game_t *idle_play_button(game_t *game, char *str, char *str2)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->prev != NULL; button = button->prev);
    for (; button->type != START; button = button->next);
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(\
    str, NULL);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
    for (; button->prev != NULL; button = button->prev);
    for (; button->type != START_2; button = button->next);
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(\
    str2, NULL);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
    return (game);
}

void redirect_idle_play_button(sfVector2i mouse_pos, game_t *game)
{
    if (mouse_pos.x >= 830 && mouse_pos.x <= 1380 &&    \
        mouse_pos.y >= 500 && mouse_pos.y <= 650)
        idle_play_button(game,                       \
        "../../ressources/sprites/menu/danseur.png", \
        "../../ressources/sprites/menu/danseur.png");
    else
        idle_play_button(game,                           \
        "../../ressources/sprites/menu/buttonplay1.png", \
        "../../ressources/sprites/menu/buttonplay2.png");
}
