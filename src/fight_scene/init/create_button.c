/*
** EPITECH PROJECT, 2019
** button.c
** File description:
** rpg
*/

#include "my_rpg.h"

button_t *create_button(char *filepath, sfVector2f size, sfVector2f position)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return (NULL);
    button->texture = sfTexture_createFromFile(filepath, NULL);
    if (button->texture == NULL)
        return (NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    button->shape = sfRectangleShape_create();
    if (button->shape == NULL)
        return (NULL);
    button->position = position;
    button->size = size;
    sfRectangleShape_setSize(button->shape, button->size);
    sfRectangleShape_setPosition(button->shape, button->position);
    sfRectangleShape_setFillColor(button->shape, sfTransparent);
    return (button);
}

int button_is_clicked(sfSound *sound, button_t *button,
sfVector2i clickPosition)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->shape);
    sfVector2f size = sfRectangleShape_getSize(button->shape);

    if (pos.x <= clickPosition.x && clickPosition.x <= (pos.x + size.x)) {
        if (pos.y <= clickPosition.y && clickPosition.y <= (pos.y + size.y)) {
            sfSound_play(sound);
            return (1);
        }
    }
    return (0);
}
