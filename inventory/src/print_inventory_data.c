/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** print_inventory_data
*/

#include "inventory.h"

void display_slots(slot_t *slot)
{
    if (slot == NULL)
        return;
    printf("Slot n°%i", slot->number);
    if (slot->item != NULL)
        printf(" : %s", slot->item->name);
    printf("\n");
    display_slots(slot->next);
}

void print_inventory_data(inventory_t *inventory)
{
    printf("***Inventory***\n");
    printf("Nb slots : %i\n", inventory->nb_slots);
    printf("Nb items : %i\n", inventory->nb_items);
    display_slots(inventory->slots);
}
