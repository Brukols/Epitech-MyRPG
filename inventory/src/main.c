/*
** EPITECH PROJECT, 2019
** inventory
** File description:
** main
*/

#include "inventory.h"

int main(int ac, char **av)
{
    item_t **items = init_items();
    inventory_t *inventory = init_inventory();

    if (items == NULL || inventory == NULL)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "graphic") == 0)
        graphics(inventory, items);
    else
        manage_inventory_with_items(inventory, items);
    destroy_items(items);
    destroy_inventory(inventory);
    return (0);
}
