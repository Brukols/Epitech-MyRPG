/*
** EPITECH PROJECT, 2019
** launch_game
** File description:
** defedner
*/

#include "my_rpg.h"

int scene_managing(game_t *game)
{
    if (game->scene->type == MENU)
        return (display_menu(game));
    if (game->scene->type == GAME)
        return (display_scene_game(game));
    return (SUCCESS);
} //POINTEURS SUR FONCTIONS

int launch_game(void)
{
    game_t *game = init_game();

    if (!game)
        return (FAILURE_EXIT);
    while (sfRenderWindow_isOpen(game->window)) {
        if (scene_managing(game) == FAILURE)
            return (FAILURE_EXIT);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
    }
    sfRenderWindow_close(game->window);
    return (SUCCESS_EXIT);
}
