/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** manage_inventory
*/

#include "inventory.h"

void which_item(inventory_t *inventory, item_t **items)
{
    char *input = NULL;
    int nb = 0;

    printf("Which item ? ");
    input = get_input();
    nb = my_getnbr(input);
    if (nb >= 2)
        printf("There are only 2 items created\n");
    else
        add_item(inventory, items, nb);
    free(input);
}

void which_slot(inventory_t *inventory)
{
    char *input = NULL;
    int nb = 0;

    printf("Which slot ? ");
    input = get_input();
    nb = my_getnbr(input);
    if (nb >= inventory->nb_slots)
        printf("Not a good n° of slot\n");
    else
        remove_item(inventory->slots, nb);
    free(input);
}

void manage_inventory_with_items(inventory_t *inventory, item_t **items)
{
    char *input = NULL;

    while (1) {
        printf("Enter command : ");
        input = get_input();
        if (my_strcmp(input, "exit") == 0)
            return;
        if (my_strcmp(input, "items") == 0)
            print_items_data(items);
        if (my_strcmp(input, "inventory") == 0)
            print_inventory_data(inventory);
        if (my_strcmp(input, "add") == 0)
            which_item(inventory, items);
        if (my_strcmp(input, "delete") == 0)
            which_slot(inventory);
        free(input);
    }
}
