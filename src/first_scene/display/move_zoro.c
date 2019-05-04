/*
** EPITECH PROJECT, 2019
** move_oro
** File description:
** my_pg
*/

#include "my_rpg.h"

void re_init_zoro(pnj_t *pnj, player_t *player, int *i)
{
    player->game_object->rect.top = 0;
    pnj->game_object->pos = init_vec2f(1060, -200);
    pnj->game_object->hitbox_pos = init_vec2f(1072, -146);
    pnj->game_object->clock = sfClock_create();
    pnj->game_object->comparison = -200;
    (*i)++;
}

void begin_speak_zoro(pnj_t *pnj, player_t *player, int *i)
{
    if (player->game_object->rect.top == 0)
        player->game_object->rect.top += 216;
    pnj->speak = true;
    pnj->next_dialog += 2;
    (*i)++;
}

void move_zoro(game_t *game, player_t *player, pnj_t *pnj)
{
    static int i = 0;

    if (i == 0)
        re_init_zoro(pnj, player, &i);
    if (i <= 2)
        first_move_zoro(pnj, &i);
    if (i == 3)
        begin_speak_zoro(pnj, player, &i);
    if (pnj->speak == false && i == 4)
        i++;
    if (i == 5)
        second_move_zoro(pnj, &i);
    if (i == 6) {
        game->quests->all_quests++;
        game->quests->quest++;
    }
}