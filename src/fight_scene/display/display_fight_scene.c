/*
** EPITECH PROJECT, 2019
** display_fight_scene.c
** File description:
** display_fight_scene.c
*/

#include "my_rpg.h"

game_t *display_fight_scene(game_t *game)
{
    display_fight_scene_objs(game);
    //display_player(game);
    display_fight_scene_buttons(game);
    return (game);
}
