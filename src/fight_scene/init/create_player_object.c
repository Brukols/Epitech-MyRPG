/*
** EPITECH PROJECT, 2019
** create_player_object.c
** File description:
** create_player_object.c
*/

#include "my_rpg.h"

object_t *create_player_object(char *filepath, sfVector2f position, sfIntRect rect)
{
    object_t *player = malloc(sizeof(object_t));

    if (player == NULL)
        return (NULL);
    player->texture = sfTexture_createFromFile(filepath, NULL);
    if (player->texture == NULL);
}
