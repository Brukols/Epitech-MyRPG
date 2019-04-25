/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create_ring
*/

#include "inventory.h"

item_t *create_ring(void)
{
    item_t *ring = malloc(sizeof(item_t));

    if (ring == NULL)
        return (NULL);
    ring->texture = NULL;
    ring->texture = sfTexture_createFromFile("ressources/Ring_50*50.png"\
                                             , NULL);
    ring->sprite = NULL;
    ring->box_t = sfTexture_createFromFile("ressources/Box_ring.png", NULL);
    ring->box_s = sfSprite_create();
    ring->sprite = sfSprite_create();
    ring->name = "Ring";
    ring->description = "A ring from your mother";
    ring->atk = 0;
    ring->pow = 5;
    sfSprite_setTexture(ring->sprite, ring->texture, sfTrue);
    sfSprite_setTexture(ring->box_s, ring->box_t, sfTrue);
    return (ring);
}
