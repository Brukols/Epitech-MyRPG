/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** destroy_inventory
*/

#include "inventory.h"

void destroy_slots(slot_t *slot)
{
    if (slot->next != NULL)
        destroy_slots(slot->next);
    if (slot->item != NULL)
        destroy_item(slot->item);
    free(slot);
}

void destroy_inventory(inventory_t *inventory)
{
    if (inventory->slots != NULL)
        destroy_slots(inventory->slots);
    free(inventory);
}
