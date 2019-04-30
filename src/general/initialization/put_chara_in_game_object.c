/*
** EPITECH PROJECT, 2019
** put_chra_in_game_object
** File description:
** my_rpg
*/

#include "my_rpg.h"

game_object_t *fill_go_of_player(game_object_t *go, player_t *player, int x, \
int y)
{
    for (; go->next; go = go->next);
    if (!(go->next = malloc(sizeof(game_object_t))))
        return (NULL);
    go->next->prev = go;
    go = go->next;
    if (!(go->texture = sfTexture_createFromFile(\
        "ressources/sprites/chara5.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->pos = init_vec2f(x, y);
    go->comparison = y;
    go->rect = init_intrect(78, 0, 78, 108);
    go->clock = sfClock_create();
    go->type = PLAYER;
    go->move_x = 0;
    go->move_y = 0;
    player->game_object = go;
    go->next = NULL;
    return (go);
}

scene_object_t *put_chara_in_game_object(scene_object_t *so, int x, int y)
{
    player_t *player = so->player;
    game_object_t *go = so->game_object;

    if (!(go = fill_go_of_player(go, player, x, y)))
        return (NULL);
    go->display = true;
    for (; go->prev; go = go->prev);
    go = sort_game_object(go);
    so->game_object = go;
    return (so);
}