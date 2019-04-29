/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** inventory
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include "my_rpg.h"

typedef struct s_item
{
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *box_t;
    sfSprite *box_s;
    char *name;
    char *description;
    int atk;
    int pow;
} item_t;

typedef struct s_slot
{
    int number;
    bool select;
    item_t *item;
    sfVector2f pos;
    sfVector2f size;
    struct s_slot *next;
} slot_t;

typedef struct s_inventory
{
    sfTexture *texture;
    sfSprite *sprite;
    int nb_slots;
    int nb_items;
    slot_t *slots;
    item_t **items;
} inventory_t;

item_t **init_items(void);
void destroy_items(item_t **items);
void destroy_item(item_t *item);
void print_items_data(item_t **items);

void graphics(inventory_t *inventory, item_t **items);

//Inventory
inventory_t *init_inventory(void);
void manage_inventory_with_items(inventory_t *inventory, item_t **items);
void print_inventory_data(inventory_t *inventory);
void destroy_inventory(inventory_t *inventory);
void add_item(inventory_t *, int);
void remove_item(slot_t *slot, int nb);

//Get Input
char *get_input(void);
char *remove_return_line(char *buffer);

//Create item
item_t *create_one_item(int id);
item_t *create_sword(void);
item_t *create_ring(void);

#endif
