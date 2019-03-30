/*
** EPITECH PROJECT, 2019
** launch_game
** File description:
** defedner
*/

#include "my_rpg.h"

game_t *scene_managing(game_t *game)
{
    enum scene_e type[1] = {FIRST_SCENE};
    game_t *(*display_scenes[1])() = {display_fs_scene};

    for (int i = 0; i < 1; i++) {
        if (game->scenes->scene == type[i])
            return (game = display_scenes[i](game));
    }
    return (NULL);
}

int launch_game(void)
{
    game_t *game = init_all_game();

    if (!game)
        return (FAILURE_EXIT);
    while (sfRenderWindow_isOpen(game->window)) {
        if (!(game = scene_managing(game)))
            return (FAILURE_EXIT);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
    }
    sfRenderWindow_close(game->window);
    return (SUCCESS_EXIT);
}
