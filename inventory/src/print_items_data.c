/*
** EPITECH PROJECT, 2019
** rog
** File description:
** display_items_data
*/

#include "inventory.h"

void print_items_data(item_t **items)
{
    for (int count = 0; items[count] != NULL; count++) {
        printf("Item n°%i = %s\n", count, items[count]->name);
        printf("Description : %s\n", items[count]->description);
        printf("Atk : %i\n", items[count]->atk);
        printf("Pow : %i\n", items[count]->pow);
        printf("\n");
    }
}
