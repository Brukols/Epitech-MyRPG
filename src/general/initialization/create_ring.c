/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create_ring
*/

#include "my_rpg.h"

item_t *create_ring(void)
{
    item_t *ring = malloc(sizeof(item_t));

    if (ring == NULL)
        return (NULL);
    if (!(ring->texture = sfTexture_createFromFile(\
        "ressources/sprites/inventory/items/Ring.png" , NULL)))
        return (NULL);
    if (!(ring->box_t = sfTexture_createFromFile(\
        "ressources/sprites/inventory/box/Box_ring.png", NULL)))
        return (NULL);
    if (!(ring->box_s = sfSprite_create()))
        return (NULL);
    if (!(ring->sprite = sfSprite_create()))
        return (NULL);
    ring->name = "Ring";
    ring->description = "A ring from your mother";
    ring->atk = 0;
    ring->pow = 5;
    sfSprite_setTexture(ring->sprite, ring->texture, sfTrue);
    sfSprite_setTexture(ring->box_s, ring->box_t, sfTrue);
    return (ring);
}
