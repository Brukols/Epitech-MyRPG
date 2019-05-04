/*
** EPITECH PROJECT, 2019
** manage_fight_scene.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

game_t *manage_fight_scene(game_t *game)
{
    display_fight_scene(game);
    fight_events(game);
    return (game);
}
