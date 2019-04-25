/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** graphics
*/

#include "inventory.h"

void graphics(inventory_t *inventory, item_t **items)
{
    sfRenderWindow *window = create_window(1980, 1020, 60);
    sfEvent event;

    add_item(inventory, items, 0);
    add_item(inventory, items, 0);
    add_item(inventory, items, 1);
    add_item(inventory, items, 1);
    add_item(inventory, items, 0);
    add_item(inventory, items, 1);
    inventory->slots->select = true;
    remove_item(inventory->slots, 3);
    if (window == NULL)
        return;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            check_event(inventory, items, event, window);
        sfRenderWindow_clear(window, sfWhite);
        display_inventory(inventory, window);
        sfRenderWindow_display(window);
    }
}
