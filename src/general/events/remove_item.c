/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** remove_item
*/

#include "inventory.h"

void remove_item(slot_t *slot, int nb)
{
    if (slot->number != nb)
        remove_item(slot->next, nb);
    else if (slot->item == NULL)
        printf("There is no item on this slot\n");
    else
        slot->item = NULL;
}
