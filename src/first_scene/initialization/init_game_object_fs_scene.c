/*
** EPITECH PROJECT, 2019
** init_game_object_fs_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

char **init_map_fs_scene(char *path)
{
    int fd = open(path, O_RDONLY);
    char *map = malloc(sizeof(char) * (2100));
    char **result = NULL;
    int verif = 0;

    if (fd == -1 || !map)
        return (NULL);
    if ((verif = read(fd, map, 2100)) == -1)
        return (NULL);
    map[verif] = '\0';
    if (!(result = str_to_word_array_for_map(map)))
        return (NULL);
    free(map);
    return (result);
}

char *next_data(char *str, int *i)
{
    int a = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!tmp)
        return (NULL);
    for (; str[*i] && str[*i] != ':'; a++, (*i)++)
        tmp[a] = str[*i];
    if (str[*i])
        *i += 1;
    tmp[a] = '\0';
    return (tmp);
}

game_object_t *init_object(game_object_t *go, char *str)
{
    int i = 0;
    char *tmp = next_data(str, &i);
    char *x = next_data(str, &i);
    char *y = next_data(str, &i);
    char *name[1] = {"shaft"};
    game_object_t *(*init_every_object[1])() = {init_shaft};

    if (!tmp || !x || !y)
        return (NULL);
    for (int i = 0; i < 1; i++) {
        if (!my_strcmp(tmp, name[i]))
            return (init_every_object[i](go, my_getnbr(x), my_getnbr(y)));
    }
    return (NULL);
}

game_object_t *init_game_object_fs_scene(void)
{
    game_object_t *go = malloc(sizeof(game_object_t));
    char **map = init_map_fs_scene("maps/map");

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