/*
** EPITECH PROJECT, 2019
** move_zoro_game_play
** File description:
** my_rpg
*/

#include "my_rpg.h"

void deplacement_zoro_x(pnj_t *pnj, int *i)
{
    if (pnj->game_object->pos.x >= 950) {
        pnj->game_object->pos.x -= 2;
        pnj->game_object->hitbox_pos.x -= 2;
    } else {
        pnj->game_object->rect.left = pnj->game_object->stock_left;
        (*i)++;
    }
}

void first_move_zoro(pnj_t *pnj, int *i)
{
    if (sfClock_getElapsedTime(pnj->game_object->clock).microseconds > 150000 \
    && *i <= 2) {
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
    } else
        deplacement_zoro_x(pnj, i);
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