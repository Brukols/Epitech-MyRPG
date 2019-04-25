/*
** EPITECH PROJECT, 2019
** init_game_object_fs_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

game_object_t *init_game_object_scene(char *str)
{
    game_object_t *go = malloc(sizeof(game_object_t));
    char **map = init_map(str);

    if (!map || !go)
        return (NULL);
    go->prev = NULL;
    for (int i = 0; map[i]; i++) {
        if (!(go = init_object(go, map[i])))
            return (NULL);
        if (!map[i + 1])
            break;
        if (!(go->next = malloc(sizeof(game_object_t))))
            return (NULL);
        go->next->prev = go;
        go = go->next;
    }
    go->next = NULL;
    for (; go->prev; go = go->prev);
    return (go);
}
