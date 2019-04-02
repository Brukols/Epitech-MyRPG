/*
** EPITECH PROJECT, 2019
** display_fs_scene
** File description:
** rpg
*/

#include "my_rpg.h"

game_t *display_fs_scene(game_t *game)
{
    display_bg_fs_scene(game);
    display_player_fs_scene(game);
    events_fs_scene(game);
    return (game);
}