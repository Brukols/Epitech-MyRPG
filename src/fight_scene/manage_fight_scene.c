/*
** EPITECH PROJECT, 2019
** manage_fight_scene.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

game_t *manage_fight_scene(game_t *game)
{
    fight_events(game);
    if (check_hp(game) != 0) {
        end_fight_scene(game);
    } else
        display_fight_scene(game);
    return (game);
}

int check_hp(game_t *game)
{
    if (game->scenes->objs->player->hp == 0) {
        if (defeated(game, "You died!") == ERROR)
            return (ERROR);
        return (1);
    } else if (game->scenes->objs->enemy->hp == 0) {
        if (defeated(game, "ENEMY is defeated.\nYou WON!") == ERROR)
            return (ERROR);
        if (game->scenes->objs->enemy->next != NULL)
            game->scenes->objs->enemy = game->scenes->objs->enemy->next;
        return (2);
    } else
        return (0);
}

int defeated(game_t *game, char *str)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;

    if (clock == NULL)
        return (ERROR);
    time = sfClock_getElapsedTime(clock);
    seconds = sfTime_asSeconds(time);
    sfText_setString(game->scenes->texts->text, str);
    display_fight_scene(game);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
    while (seconds < 4.0) {
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time);
    }
    sfClock_destroy(clock);
    return (0);
}

void end_fight_scene(game_t *game)
{
    while (game->scenes->prev != NULL)
        game->scenes = game->scenes->prev;
    while (game->scenes->scene != FIRST_SCENE)
        game->scenes = game->scenes->next;
}
