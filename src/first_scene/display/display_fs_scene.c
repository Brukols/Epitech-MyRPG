/*
** EPITECH PROJECT, 2019
** display_fs_scene
** File description:
** rpg
*/

#include "my_rpg.h"

game_t *display_fs_scene(game_t *game)
{
    gameplay(game);
    unlock_smth_fs_scene(game);
    game->scenes->objs->game_object = sort_game_object(game->scenes->objs->game_object);
    if (go_in_another_scene_fs_scene(game) == true)
        return (game);
    move_all_the_scene(game);
    display_bg(game);
    display_player(game);
    display_game_object(game);
    game->scenes->objs->particle = display_particle(game);
    display_inventory(game);
    display_buttons(game);
    display_texts_fs_scene(game);
    display_quests(game, sfBlack);
    events_fs_scene(game);
    return (game);
}
