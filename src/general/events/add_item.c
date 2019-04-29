/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** add_item
*/

#include "my_rpg.h"

void find_free_slot(slot_t *slot, item_t **items, int id)
{
    if (slot->item != NULL)
        find_free_slot(slot->next, items, id);
    else {
        slot->item = create_one_item(id);
    }
}

void add_item(inventory_t *inventory, int id)
{
    if (inventory->nb_slots == inventory->nb_items)
        return;
    find_free_slot(inventory->slots, inventory->items, id);
    inventory->nb_items = inventory->nb_items + 1;
}
