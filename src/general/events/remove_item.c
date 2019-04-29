/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** remove_item
*/

#include "my_rpg.h"

void remove_item(slot_t *slot, int nb)
{
    if (slot->number != nb)
        remove_item(slot->next, nb);
    else if (slot->item == NULL)
        return;
    else
        slot->item = NULL;
}
