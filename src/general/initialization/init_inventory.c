/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init_inventory
*/

#include "my_rpg.h"

slot_t *init_slot(int nb_slots, int number)
{
    slot_t *slot = NULL;
    static sfVector2f pos_item = {5, 317};

    if (nb_slots == number)
        return (slot);
    if (!(slot = malloc(sizeof(slot_t))))
        return (NULL);
    slot->number = number;
    slot->item = NULL;
    slot->select = false;
    slot->size = init_vec2f(50, 50);
    slot->pos = init_vec2f(pos_item.x, pos_item.y);
    pos_item.y += 58;
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
    if (!(inventory->texture = sfTexture_createFromFile(\
        "ressources/sprites/Inventory_bar2.png", NULL)))
        return (NULL);
    if (!(inventory->sprite = sfSprite_create()))
        return (NULL);
    if (!(inventory->slots = init_slot(inventory->nb_slots, 0)))
        return (NULL);
    if (!(inventory->items = init_items()))
        return (NULL);
    sfSprite_setPosition(inventory->sprite, pos);
    sfSprite_setTexture(inventory->sprite, inventory->texture, sfTrue);
    return (inventory);
}
