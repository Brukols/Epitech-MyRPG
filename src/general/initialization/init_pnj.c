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

char **init_all(char *str, int *i)
{
    char **all = malloc(sizeof(char *) * 9);

    if (!all)
        return (NULL);
    all[8] = NULL;
    for (int a = 0; a < 7; a++) {
        all[a] = next_for_pnj(str, i);
        if (!all[a])
            return (NULL);
    }
    all[7] = init_what_texture(str, i);
    if (!all[7])
        return (NULL);
    return (all);
}

game_object_t *fill_game_object_pnj(game_object_t *go, char **all)
{
    if (!(go->next = malloc(sizeof(game_object_t))))
        return (NULL);
    go->next->prev = go;
    go = go->next;
    go->next = NULL;
    go->pos = init_vec2f(my_getnbr(all[1]), my_getnbr(all[2]));
    go->comparison = my_getnbr(all[2]);
    go->type = PNJ;
    go->move_x = 0;
    go->move_y = 0;
    if (!(go->texture = sfTexture_createFromFile(all[7], NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->scale = init_vec2f(1, 1);
    go->rect = init_intrect(my_getnbr(all[3]), my_getnbr(all[4]), \
    my_getnbr(all[5]), my_getnbr(all[6]));
    go->hitbox_pos = init_vec2f(my_getnbr(all[1]) + 12, my_getnbr(all[2]) + 54);
    go->hitbox_size = init_vec2f(51, 54);
    return (go);
}

pnj_t *fill_a_pnj(pnj_t *pnj, game_object_t *go, char *str)
{
    int i = 0;
    char **all = init_all(str, &i);

    if (!all)
        return (NULL);
    for (; go->next; go = go->next);
    if (!(pnj->game_object = fill_game_object_pnj(go, all)))
        return (NULL);
    pnj->game_object->stock_top = my_getnbr(all[4]);
    pnj->game_object->stock_left = my_getnbr(all[3]);
    if (!(pnj->name = my_strdup(all[0])))
        return (NULL);
    if (!(pnj->discuss = init_discuss(str, &i)))
        return (NULL);
    pnj->next_dialog = 0;
    pnj->speak = false;
    pnj->game_object->display = true;
    pnj->has_talk_with = false;
    free_array(all);
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
        if (!(pnj = fill_a_pnj(pnj, so->game_object, map[i])))
            return (NULL);
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
