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
    scenes_t *(*init_every_scene[4])() = {init_scene_menu, init_intro, \
init_first_scene, init_house_1_scene};

    if (scenes == NULL)
        return NULL;
    scenes->prev = NULL;
    for (int i = 0; i < 4; i++) {
        scenes = init_every_scene[i](scenes);
        if (i == 3)
            break;
        scenes->next = malloc(sizeof(scenes_t));
        if (!scenes->next)
            return (NULL);
        scenes->next->prev = scenes;
        scenes = scenes->next;
    }
    scenes->next = NULL;
    for (; scenes->prev->prev; scenes = scenes->prev);
    return (scenes);
}

game_t *init_all_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return (NULL);
    game->window = create_window(1920, 1080, 60);
    if (!game->window)
        return NULL;
    game->quests = init_quests();
    if (!game->quests)
        return (NULL);
    if (!(game->scenes = init_scenes()))
        return (NULL);
    return (game);
}
