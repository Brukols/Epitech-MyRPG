/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create_sword
*/

#include "my_rpg.h"

item_t *create_sword(void)
{
    item_t *sword = malloc(sizeof(item_t));

    if (sword == NULL)
        return (NULL);
    if (!(sword->texture = sfTexture_createFromFile(\
        "ressources/sprites/inventory/items/Sword.png" , NULL)))
        return (NULL);
    if (!(sword->box_t = sfTexture_createFromFile(\
        "ressources/sprites/inventory/box/Box_sword.png", NULL)))
        return (NULL);
    if (!(sword->box_s = sfSprite_create()))
        return (NULL);
    if (!(sword->sprite = sfSprite_create()))
        return (NULL);
    sword->name = "Sword";
    sword->description = "An old sword found on a cellar";
    sword->atk = 5;
    sword->pow = 0;
    sfSprite_setTexture(sword->sprite, sword->texture, sfTrue);
    sfSprite_setTexture(sword->box_s, sword->box_t, sfTrue);
    return (sword);
}
