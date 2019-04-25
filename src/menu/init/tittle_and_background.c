/*
** EPITECH PROJECT, 2019
** init tittle
** File description:
** rpg
*/

#include "my_rpg.h"

background_t *init_background(background_t *background)
{
    background->texture = sfTexture_createFromFile(\
    "ressources/sprites/menu/tittle.png", NULL);
    background->sprite = sfSprite_create();
    background->pos.x = 0;
    background->pos.y = 0;
    background->clock = sfClock_create();
    sfSprite_setPosition(background->sprite, background->pos);
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    return (background);
}

texts_t *init_title(void)
{
    texts_t *tittle = malloc(sizeof(texts_t));

    if (tittle == NULL)
        return NULL;
    tittle->font = sfFont_createFromFile(\
    "ressources/font/tittle.ttf");
    tittle->text = sfText_create();
    tittle->pos.x = 460;
    tittle->pos.y = 170;
    sfText_setString(tittle->text, "Polyppoppy's World");
    sfText_setFont(tittle->text, tittle->font);
    sfText_setCharacterSize(tittle->text, 170);
    sfText_setColor(tittle->text, sfBlack);
    sfText_setPosition(tittle->text, tittle->pos);
    return (tittle);
}
