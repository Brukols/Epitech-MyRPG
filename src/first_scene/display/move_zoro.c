/*
** EPITECH PROJECT, 2019
** move_oro
** File description:
** my_pg
*/

#include "my_rpg.h"

void first_move_zoro(pnj_t *pnj, int *i)
{
    if (sfClock_getElapsedTime(pnj->game_object->clock).microseconds > 150000 && *i <= 2) {
        pnj->game_object->rect.left += 78;
        sfClock_restart(pnj->game_object->clock);
    }
    if (pnj->game_object->rect.left == pnj->game_object->stock_left + 156)
        pnj->game_object->rect.left = pnj->game_object->stock_left - 78;
    if (pnj->game_object->pos.y >= 530 && (*i) == 1) {
        pnj->game_object->rect.top += 108;
        (*i)++;
    }
    if (pnj->game_object->pos.y < 530) {
        pnj->game_object->pos.y += 2;
        pnj->game_object->hitbox_pos.y += 2;
        pnj->game_object->comparison += 2;
    } else {
        if (pnj->game_object->pos.x >= 950) {
            pnj->game_object->pos.x -= 2;
            pnj->game_object->hitbox_pos.x -= 2;
        } else {
            pnj->game_object->rect.left = pnj->game_object->stock_left;
            (*i)++;
        }
    }
}

void second_move_zoro(pnj_t *pnj, int *i)
{
    pnj->game_object->rect.top = pnj->game_object->stock_top;
    if (sfClock_getElapsedTime(pnj->game_object->clock).microseconds > 150000) {
        pnj->game_object->rect.left += 78;
        sfClock_restart(pnj->game_object->clock);
    }
    if (pnj->game_object->rect.left == pnj->game_object->stock_left + 156)
        pnj->game_object->rect.left = pnj->game_object->stock_left - 78;
    pnj->game_object->pos.y += 2;
    pnj->game_object->comparison += 2;
    pnj->game_object->hitbox_pos.y += 2;
    if (pnj->game_object->pos.y > 600) {
        pnj->game_object->rect.left = pnj->game_object->stock_left;
        *i += 1;
    }
}

void move_zoro(game_t *game, player_t *player, pnj_t *pnj)
{
    static int i = 0;

    if (i == 0) {
        player->game_object->rect.top = 0;
        pnj->game_object->pos = init_vec2f(1060, -200);
        pnj->game_object->hitbox_pos = init_vec2f(1072, -146);
        pnj->game_object->clock = sfClock_create();
        pnj->game_object->comparison = -200;
        i++;
    }
    if (i <= 2)
        first_move_zoro(pnj, &i);
    if (i == 3) {
        if (player->game_object->rect.top == 0)
            player->game_object->rect.top += 216;
        pnj->speak = true;
        pnj->next_dialog += 2;
        i++;
    }
    if (pnj->speak == false && i == 4)
        i++;
    if (i == 5)
        second_move_zoro(pnj, &i);
    if (i == 6) {
        game->quests->all_quests = SAVE_LUCY;
        game->quests->quest++;
    }
}