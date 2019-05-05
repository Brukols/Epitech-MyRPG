/*
** EPITECH PROJECT, 2019
** init_stats
** File description:
** my_rpg
*/

#include "my_rpg.h"

level_bar_t *init_level_bar(void)
{
    level_bar_t *level_bar = malloc(sizeof(level_bar_t));

    if (!level_bar) 
        return (NULL);
    level_bar->sprite = sfSprite_create();
    level_bar->texture = sfTexture_createFromFile(\
    "ressources/sprites/progress_bar.png", NULL);
    level_bar->pos = init_vec2f(130, 270);
    level_bar->rect = init_intrect(0, 0, 250, 25);
    if (!level_bar->texture || !level_bar->sprite)
        return (NULL);
    return (level_bar);
}

stats_t *init_stats(void)
{
    stats_t *stats = malloc(sizeof(stats_t));

    if (!stats)
        return (NULL);
    stats->level_bar = init_level_bar();
    stats->player_stats = init_player_stats();
    if (!stats->level_bar || !stats->player_stats)
        return (NULL);
    return (stats);
}