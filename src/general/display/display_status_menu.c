/*
** EPITECH PROJECT, 2019
** display_status_menu
** File description:
** my_rpg
*/

#include "my_rpg.h"

void display_progress_bar(game_t *game, level_bar_t *stats, player_t *player)
{
    int tmp;

    player->current_level = player->level;
    tmp = (player->level - player->current_level) * 10;
    stats->rect.top = 25 * tmp;
    sfSprite_setPosition(stats->sprite, stats->pos);
    sfSprite_setTexture(stats->sprite, stats->texture, sfFalse);
    sfSprite_setTextureRect(stats->sprite, stats->rect);
    sfRenderWindow_drawSprite(game->window, stats->sprite, NULL);
}

void display_status_menu(game_t *game)
{
    buttons_t *button;
    scenes_t *scenes = game->scenes;

    for (; scenes->prev; scenes = scenes->prev);
    for (; scenes->scene != FIRST_SCENE; scenes = scenes->next);
    button = game->scenes->buttons;
    for (; button->type != STATUS_MENU; button = button->next);
    if (button->display == false)
        return;
    display_progress_bar(game, scenes->stats->level_bar, scenes->objs->player);
    display_player_stats(game, scenes->stats->player_stats, \
    scenes->objs->player);
}