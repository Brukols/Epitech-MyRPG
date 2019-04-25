/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create_sword
*/

#include "inventory.h"

item_t *create_sword(void)
{
    item_t *sword = malloc(sizeof(item_t));

    if (sword == NULL)
        return (NULL);
    sword->texture = NULL;
    sword->texture = sfTexture_createFromFile("ressources/Sword_50*50.png"\
                                              , NULL);
    sword->sprite = NULL;
    sword->box_t = sfTexture_createFromFile("ressources/Box_sword.png", NULL);
    sword->box_s = sfSprite_create();
    sword->sprite = sfSprite_create();
    sword->name = "Sword";
    sword->description = "An old sword found on a cellar";
    sword->atk = 5;
    sword->pow = 0;
    sfSprite_setTexture(sword->sprite, sword->texture, sfTrue);
    sfSprite_setTexture(sword->box_s, sword->box_t, sfTrue);
    return (sword);
}
