/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** destroy_items
*/

#include "inventory.h"

void destroy_item(item_t *item)
{
    if (item == NULL)
        return;
    if (item->texture != NULL)
        sfTexture_destroy(item->texture);
    if (item->sprite != NULL)
        sfSprite_destroy(item->sprite);
    free(item);
}

void destroy_items(item_t **items)
{
    for (int count = 0; items[count] != NULL; count++) {
        destroy_item(items[count]);
    }
    free(items);
}
