/*
** EPITECH PROJECT, 2019
** cloak
** File description:
** my_rpg
*/

#include "my_rpg.h"

item_t *create_cloak(void)
{
    item_t *item = malloc(sizeof(item_t));

    if (item == NULL)
        return (NULL);
    if (!(item->texture = sfTexture_createFromFile(\
        "ressources/sprites/inventory/items/Cloak.png" , NULL)))
        return (NULL);
    if (!(item->box_t = sfTexture_createFromFile(\
        "ressources/sprites/inventory/box/Box_cloak.png", NULL)))
        return (NULL);
    if (!(item->box_s = sfSprite_create()))
        return (NULL);
    if (!(item->sprite = sfSprite_create()))
        return (NULL);
    item->name = "Cloak";
    item->atk = 0;
    item->pow = 20;
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    sfSprite_setTexture(item->box_s, item->box_t, sfTrue);
    return (item);
}