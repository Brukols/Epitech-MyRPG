/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** select play button
*/

#include "my_rpg.h"

sfSprite *first_play_sprite(game_t *game)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->prev != NULL; button = button->prev);
    for (; button->type != START; button = button->next);
    return(button->sprite);
}

sfSprite *scnd_play_sprite(game_t *game)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->prev != NULL; button = button->prev);
    for (; button->type != START_2; button = button->next);
    return(button->sprite);
}

sfTexture *first_play_texture(game_t *game)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->prev != NULL; button = button->prev);
    for (; button->type != START; button = button->next);
    return(button->texture);
}

sfTexture *scnd_play_texture(game_t *game)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->prev != NULL; button = button->prev);
    for (; button->type != START; button = button->next);
    return(button->texture);
}
