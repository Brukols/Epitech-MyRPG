/*
** EPITECH PROJECT, 2019
** create_key.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

item_t *create_key(void)
{
    item_t *ring = malloc(sizeof(item_t));

    if (ring == NULL)
        return (NULL);
    if (!(ring->texture = sfTexture_createFromFile(\
        "ressources/sprites/inventory/items/key.png" , NULL)))
        return (NULL);
    if (!(ring->sprite = sfSprite_create()))
        return (NULL);
    ring->box_s = NULL;
    ring->name = "Key";
    ring->description = "To open a chest";
    ring->atk = 0;
    ring->pow = 0;
    sfSprite_setTexture(ring->sprite, ring->texture, sfTrue);
    return (ring);
}