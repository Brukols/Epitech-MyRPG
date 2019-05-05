/*
** EPITECH PROJECT, 2019
** display_player_stat
** File description:
** my_rpg
*/

#include "my_rpg.h"

void display_level(game_t *game, player_stats_t *stats, \
player_t *player)
{
    char *str;

    for (; stats->stat != LEVEL; stats = stats->next);
    if (!(str = nbr_to_str(player->current_level)))
        return;
    sfText_setString(stats->text, str);
    sfRenderWindow_drawText(game->window, stats->text, NULL);
    free(str);
}

void display_life(game_t *game, player_stats_t *stats, \
player_t *player)
{
    char *str;
    char *str_2;

    for (; stats->stat != LIFE; stats = stats->next);
    if (!(str = nbr_to_str(player->hp)))
        return;
    if (!(str_2 = my_strdupcat("HP    ", str)))
        return;
    sfText_setString(stats->text, str_2);
    sfRenderWindow_drawText(game->window, stats->text, NULL);
    free(str);
    free(str_2);
}

void display_power(game_t *game, player_stats_t *stats, \
player_t *player)
{
    char *str;
    char *str_2;

    for (; stats->stat != POWER; stats = stats->next);
    if (!(str = nbr_to_str(player->power)))
        return;
    if (!(str_2 = my_strdupcat("Power    ", str)))
        return;
    sfText_setString(stats->text, str_2);
    sfRenderWindow_drawText(game->window, stats->text, NULL);
    free(str);
    free(str_2);
}

void display_attack(game_t *game, player_stats_t *stats, \
player_t *player)
{
    char *str;
    char *str_2;

    for (; stats->stat != ATK; stats = stats->next);
    if (!(str = nbr_to_str(player->attack)))
        return;
    if (!(str_2 = my_strdupcat("Attack    ", str)))
        return;
    sfText_setString(stats->text, str_2);
    sfRenderWindow_drawText(game->window, stats->text, NULL);
    free(str);
    free(str_2);
}

void display_player_stats(game_t *game, player_stats_t *stats, \
player_t *player)
{
    display_level(game, stats, player);
    display_life(game, stats, player);
    display_power(game, stats, player);
    display_attack(game, stats, player);
}