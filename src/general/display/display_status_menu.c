/*
** EPITECH PROJECT, 2019
** display_status_menu
** File description:
** my_rpg
*/

#include "my_rpg.h"

void display_progress_bar(game_t *game)
{
    level_bar_t *stats = game->scenes->stats->level_bar;
    player_t *player = game->scenes->objs->player;
    int tmp = (player->level - player->current_level) * 10;

    stats->rect.top = 25 * tmp;
    sfSprite_setPosition(stats->sprite, stats->pos);
    sfSprite_setTexture(stats->sprite, stats->texture, sfFalse);
    sfSprite_setTextureRect(stats->sprite, stats->rect);
    sfRenderWindow_drawSprite(game->window, stats->sprite, NULL);
}

void display_status_menu(game_t *game)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->type != STATUS_MENU; button = button->next);
    if (button->display == false)
        return;
    display_progress_bar(game);
    display_player_stats(game);
}