/*
** EPITECH PROJECT, 2019
** change_dialog2
** File description:
** my_rp
*/

#include "my_rpg.h"

void re_init_pnj_dialog(pnj_t *pnj)
{
    pnj->game_object->rect.top = pnj->game_object->stock_top;
    pnj->next_dialog = 0;
    pnj->speak = false;
}