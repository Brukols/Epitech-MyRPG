/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display_inventory
*/

#include "inventory.h"

void display_inventory(inventory_t *inventory, sfRenderWindow *window)
{
    sfVector2f pos_item = {5, 317};
    sfVector2f pos_box = {64, 200};

    sfRenderWindow_drawSprite(window, inventory->sprite, NULL);
    for (slot_t *slot = inventory->slots; slot != NULL; slot = slot->next) {
        if (slot->item != NULL) {
            sfSprite_setPosition(slot->item->sprite, pos_item);
            sfRenderWindow_drawSprite(window, slot->item->sprite, NULL);
        }
        if (slot->item != NULL && slot->select == true) {
            sfSprite_setPosition(slot->item->box_s, pos_box);
            sfRenderWindow_drawSprite(window, slot->item->box_s, NULL);
        }
        pos_item.y += 58;
        pos_box.y += 58;
    }
}
