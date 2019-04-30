/*
** EPITECH PROJECT, 2019
** game_object.c
** File description:
** rpg
*/

#include "my_rpg.h"

object_t *create_object(char *filepath, sfVector2f position)
{
    object_t *object = malloc(sizeof(object_t));

    if (object == NULL)
        return (NULL);
    object->texture = sfTexture_createFromFile(filepath, NULL);
    if (object->texture == NULL)
        return (NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->position = position;
    return (object);
}

void destroy_object(object_t *object)
{
    if (object == NULL)
        return;
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    free(object);
}
