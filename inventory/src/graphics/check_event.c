/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check_event
*/

#include "inventory.h"

void check_event(inventory_t *inventory, item_t **items, \
                 sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}
