/*
** EPITECH PROJECT, 2019
** move_the_master
** File description:
** my_rpg
*/

#include "my_rpg.h"

void re_init_the_master(pnj_t *pnj, int *i)
{
    pnj->game_object->pos = init_vec2f(850, -200);
    pnj->game_object->hitbox_pos = init_vec2f(862, -146);
    pnj->game_object->clock = sfClock_create();
    pnj->game_object->comparison = -200;
    (*i)++;
}

void first_move_master(pnj_t *pnj, int *i)
{
    if (sfClock_getElapsedTime(pnj->game_object->clock).microseconds > \
    150000) {
        pnj->game_object->rect.left += 78;
        sfClock_restart(pnj->game_object->clock);
    }
    if (pnj->game_object->rect.left == pnj->game_object->stock_left + 156)
        pnj->game_object->rect.left = pnj->game_object->stock_left - 78;
    pnj->game_object->pos.y += 2;
    pnj->game_object->hitbox_pos.y += 2;
    pnj->game_object->comparison += 2;
    if (pnj->game_object->pos.y > 300) {
        pnj->game_object->rect.top = pnj->game_object->stock_top;
        *i += 1;
    }
}

void move_the_master(game_t *game, pnj_t *pnj)
{
    static int i = 0;

    if (i == 0)
        re_init_the_master(pnj, &i);
    if (i == 1)
        first_move_master(pnj, &i);
    if (i == 2) {
        pnj->next_dialog = 2;
        pnj->speak = true;
        i++;
    }
    if (pnj->speak == false && i == 3)
        i++;
    if (i == 4) {
        pnj->game_object->display = false;
        game->quests->quest++;
        game->quests->all_quests++;
    }
}