/*
** EPITECH PROJECT, 2019
** fight_events.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void fight_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.mouseButton.type == sfEvtMouseButtonPressed)
            manage_fight_scene_buttons_events(game);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->window);
    }
    if (game->scenes->objs->player->attacking)
        player_attack_animation(game);
}
