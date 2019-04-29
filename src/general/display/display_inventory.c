/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display_inventory
*/

#include "my_rpg.h"

void display_inventory(game_t *game)
{
    inventory_t *inventory = game->scenes->objs->player->inventory;
    sfRenderWindow *window = game->window;
    sfVector2f pos_box = {64, 200};

    sfRenderWindow_drawSprite(window, inventory->sprite, NULL);
    for (slot_t *slot = inventory->slots; slot != NULL; slot = slot->next) {
        if (slot->item != NULL) {
            sfSprite_setPosition(slot->item->sprite, slot->pos);
            sfRenderWindow_drawSprite(window, slot->item->sprite, NULL);
        }
        if (slot->item != NULL && slot->select == true && slot->item->box_s) {
            sfSprite_setPosition(slot->item->box_s, pos_box);
            sfRenderWindow_drawSprite(window, slot->item->box_s, NULL);
        }
        pos_box.y += 58;
    }
}
