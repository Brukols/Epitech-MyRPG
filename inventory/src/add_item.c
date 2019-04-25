/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** add_item
*/

#include "inventory.h"

void find_free_slot(slot_t *slot, item_t **items, int id)
{
    if (slot->item != NULL)
        find_free_slot(slot->next, items, id);
    else
        slot->item = create_one_item(id);
}

void add_item(inventory_t *inventory, item_t **items, int id)
{
    if (inventory->nb_slots == inventory->nb_items) {
        printf("No more slots available\n");
        return;
    }
    find_free_slot(inventory->slots, items, id);
    inventory->nb_items = inventory->nb_items + 1;
}
