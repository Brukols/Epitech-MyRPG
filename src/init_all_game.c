/*
** EPITECH PROJECT, 2019
** init_all_game
** File description:
** my_rpg
*/

#include "my_rpg.h"

scenes_t *init_scenes(void)
{
    scenes_t *scenes = malloc(sizeof(scenes_t));

    if (scenes == NULL)
        return NULL;
    scenes->prev = NULL;
    /*if (!(scenes = init_first_scene(scenes)))
      return (NULL);*/
    if ((scenes = init_scene_menu(scenes)) == NULL)
      return NULL;
    scenes->next = NULL;
    return (scenes);
}

game_t *init_all_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return (NULL);
    game->window = create_window(1980, 1020, 32);
    if (!game->window)
        return NULL;
    if (!(game->scenes = init_scenes()))
        return (NULL);
    return (game);
}
