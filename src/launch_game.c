/*
** EPITECH PROJECT, 2019
** launch_game
** File description:
** defedner
*/

#include "my_rpg.h"

game_t *scene_managing(game_t *game)
{
<<<<<<< HEAD
    enum scene_e type[] = {INTRO, MENU, FIRST_SCENE, PLAYER_HOUSE, FIGHT, ZORO_HOUSE, SETTINGS};
    game_t *(*display_scenes[])() = {display_intro, display_menu, \
                                     display_fs_scene, display_player_house, manage_fight_scene, display_zoro_house, display_settings_scene};
=======
    enum scene_e type[] = {INTRO, MENU, FIRST_SCENE, PLAYER_HOUSE, FIGHT, \
        ZORO_HOUSE};
    game_t *(*display_scenes[])() = {display_intro, display_menu, \
        display_fs_scene, display_player_house, manage_fight_scene, \
        display_zoro_house};
>>>>>>> d96de1f4e7605f2215c8bb03209492d7f2f2f66e

    for (int i = 0; i < 7; i++) {
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
        if (!(game = scene_managing(game))) {
            sfRenderWindow_close(game->window);
            return (FAILURE_EXIT);
        }
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
    }
    sfRenderWindow_close(game->window);
    destroy_musics(game);
    return (SUCCESS_EXIT);
}
