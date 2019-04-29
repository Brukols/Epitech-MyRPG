/*
** EPITECH PROJECT, 2019
** player_have_the_key
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool player_have_the_key(player_t *player)
{
    slot_t *slot = player->inventory->slots;

    for (; slot && slot->item; slot = slot->next) {
        if (my_strcmp(slot->item->name, "Key") == 0)
            return (true);
    }
    return (false);
}