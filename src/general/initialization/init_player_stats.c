/*
** EPITECH PROJECT, 2019
** init_player_stats
** File description:
** my_rog
*/

#include "my_rpg.h"

player_stats_t *fill_level(player_stats_t *stats)
{
    sfColor color = {174, 61, 61, 255};

    stats->stat = LEVEL;
    stats->text = sfText_create();
    stats->font = sfFont_createFromFile("ressources/font/quest_font.otf");
    stats->color = sfRed;
    stats->pos = init_vec2f(120, 120);
    if (!stats->text || !stats->font)
        return (NULL);
    sfText_setCharacterSize(stats->text, 50);
    sfText_setFont(stats->text, stats->font);
    sfText_setPosition(stats->text, stats->pos);
    sfText_setColor(stats->text, color);
    return (stats);
}

player_stats_t *fill_life(player_stats_t *stats)
{
    sfColor color = {174, 61, 61, 255};

    stats->stat = LIFE;
    stats->text = sfText_create();
    stats->font = sfFont_createFromFile("ressources/font/quest_font.otf");
    stats->color = sfRed;
    stats->pos = init_vec2f(100, 380);
    if (!stats->text || !stats->font)
        return (NULL);
    sfText_setCharacterSize(stats->text, 30);
    sfText_setFont(stats->text, stats->font);
    sfText_setPosition(stats->text, stats->pos);
    sfText_setColor(stats->text, color);
    return (stats);
}

player_stats_t *fill_power(player_stats_t *stats)
{
    sfColor color = {174, 61, 61, 255};

    stats->stat = POWER;
    stats->text = sfText_create();
    stats->font = sfFont_createFromFile("ressources/font/quest_font.otf");
    stats->color = sfRed;
    stats->pos = init_vec2f(100, 420);
    if (!stats->text || !stats->font)
        return (NULL);
    sfText_setCharacterSize(stats->text, 30);
    sfText_setFont(stats->text, stats->font);
    sfText_setPosition(stats->text, stats->pos);
    sfText_setColor(stats->text, color);
    return (stats);
}

player_stats_t *fill_attack(player_stats_t *stats)
{
    sfColor color = {174, 61, 61, 255};

    stats->stat = ATK;
    stats->text = sfText_create();
    stats->font = sfFont_createFromFile("ressources/font/quest_font.otf");
    stats->color = sfRed;
    stats->pos = init_vec2f(100, 460);
    if (!stats->text || !stats->font)
        return (NULL);
    sfText_setCharacterSize(stats->text, 30);
    sfText_setFont(stats->text, stats->font);
    sfText_setPosition(stats->text, stats->pos);
    sfText_setColor(stats->text, color);
    return (stats);
}

player_stats_t *init_player_stats(void)
{
    player_stats_t *player_stats = malloc(sizeof(player_stats_t));
    player_stats_t *(*fill_player_stats[])() = {fill_level, fill_life, \
        fill_power, fill_attack};

    if (!player_stats)
        return (NULL);
    player_stats->prev = NULL;
    for (int i = 0; i < 4; i++) {
        if (!(player_stats = fill_player_stats[i](player_stats)))
            return (NULL);
        if (i == 3)
            break;
        player_stats->next = malloc(sizeof(player_stats_t));
        if (!player_stats->next)
            return (NULL);
        player_stats->next->prev = player_stats;
        player_stats = player_stats->next;
    }
    player_stats->next = NULL;
    for (; player_stats->prev; player_stats = player_stats->prev);
    return (player_stats);
}