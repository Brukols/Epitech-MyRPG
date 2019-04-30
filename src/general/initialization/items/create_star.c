/*
** EPITECH PROJECT, 2019
** star
** File description:
** my_rpg
*/

#include "my_rpg.h"

item_t *create_star(void)
{
    item_t *item = malloc(sizeof(item_t));

    if (item == NULL)
        return (NULL);
    if (!(item->texture = sfTexture_createFromFile(\
        "ressources/sprites/inventory/items/Star.png" , NULL)))
        return (NULL);
    if (!(item->box_t = sfTexture_createFromFile(\
        "ressources/sprites/inventory/box/Box_star.png", NULL)))
        return (NULL);
    if (!(item->box_s = sfSprite_create()))
        return (NULL);
    if (!(item->sprite = sfSprite_create()))
        return (NULL);
    item->name = "Star";
    item->atk = 8;
    item->pow = 8;
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    sfSprite_setTexture(item->box_s, item->box_t, sfTrue);
    return (item);
}