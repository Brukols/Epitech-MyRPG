/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init_inventory
*/

#include "inventory.h"

slot_t *init_slot(int nb_slots, int number)
{
    slot_t *slot = NULL;

    if (nb_slots == number)
        return (slot);
    slot = malloc(sizeof(slot_t));
    slot->number = number;
    slot->item = NULL;
    slot->select = false;
    slot->next = init_slot(nb_slots, number + 1);
    return (slot);
}

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));
    sfVector2f pos = {0, 300};

    if (inventory == NULL)
        return (NULL);
    inventory->nb_slots = 6;
    inventory->nb_items = 0;
    inventory->texture = sfTexture_createFromFile("ressources/Inventory_bar2.png" \
                                                  , NULL);
    inventory->sprite = sfSprite_create();
    inventory->slots = init_slot(inventory->nb_slots, 0);
    sfSprite_setPosition(inventory->sprite, pos);
    sfSprite_setTexture(inventory->sprite, inventory->texture, sfTrue);
    return (inventory);
}
