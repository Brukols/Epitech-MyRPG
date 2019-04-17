/*
** EPITECH PROJECT, 2019
** init_pnj.c
** File description:
** myè_rpg
*/

#include "my_rpg.h"

char *next_for_pnj(char *str, int *i)
{
    int a = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!tmp)
        return (NULL);
    for (; str[*i] && str[*i] != ':'; *i += 1, a++)
        tmp[a] = str[*i];
    *i += 1;
    tmp[a] = '\0';
    return (tmp);
}

game_object_t *fill_go_pnj(game_object_t *go, char *name, int x, int y)
{
    char *arr[1] = {"freddy"};
    game_object_t *(*fill_pnj[1])() = {freddy};

    for (int i = 0; i < 1; i++) {
        if (my_strcmp(arr[i], name) == 0)
            return (fill_pnj[i](go, x, y));
    }
    return (NULL);
}

pnj_t *fill_pnj(pnj_t *pnj, game_object_t *go, char *str)
{
    int i = 0;
    char *x;
    char *y;

    for (; go->next; go = go->next);
    if (!(go->next = malloc(sizeof(game_object_t))))
        return (NULL);
    go->next->prev = go;
    go = go->next;
    go->next = NULL;
    if (!(pnj->name = next_for_pnj(str, &i)))
        return (NULL);
    if (!(x = next_for_pnj(str, &i)) || !(y = next_for_pnj(str, &i)))
        return (NULL);
    pnj->next_dialog = 0;
    if (!(pnj->discuss = init_discuss(str, &i)))
        return (NULL);
    if (!(pnj->game_object = fill_go_pnj(go, pnj->name, my_getnbr(x), \
        my_getnbr(y))))
        return (NULL);
    return (pnj);
}

scene_object_t *init_pnj(scene_object_t *so, char *path)
{
    char **map = init_map(path);
    pnj_t *pnj = malloc(sizeof(pnj_t));

    if (!map || !pnj)
        return (NULL);
    pnj->prev = NULL;
    for (int i = 0; map[i]; i++) {
        if (!(pnj = fill_pnj(pnj, so->game_object, map[i])))
            return (NULL);
        pnj->speak = false;
        if (!map[i + 1])
            break;
        if (!(pnj->next = malloc(sizeof(pnj_t))))
            return (NULL);
        pnj->next->prev = pnj;
        pnj = pnj->next;
    }
    pnj->next = NULL;
    for (; pnj->prev; pnj = pnj->prev);
    so->pnj = pnj;
    return (so);
}