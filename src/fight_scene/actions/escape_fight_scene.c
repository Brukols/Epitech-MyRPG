/*
** EPITECH PROJECT, 2019
** escape_fight_scene.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int escape_fight_scene(game_t *game)
{
    int escape_status = rand_action(100);

    if (escape_status >= 50) {
        if (escape_exit(game) == ERROR)
            return (ERROR);
        game->scenes->objs->enemy = game->scenes->objs->enemy->next;
        end_fight_scene(game);
        return (1);
    } else {
        sfText_setString(game->scenes->texts->text, \
        "PLAYER tries to escape: it failed!");
        display_fight_scene(game);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        if (wait_n_seconds(1.5) == ERROR)
            return (ERROR);
        enemy_attack(game);
    }
    return (0);
}

int escape_exit(game_t *game)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds = 0;

    if (clock == NULL)
        return (ERROR);
    time = sfClock_getElapsedTime(clock);
    seconds = sfTime_asSeconds(time);
    sfText_setString(game->scenes->texts->text, "PLAYER escape the fight!");
    display_fight_scene(game);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
    while (seconds < 3.0) {
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time);
    }
    sfText_setString(game->scenes->texts->text, " ");
    sfClock_destroy(clock);
    return (0);
}
