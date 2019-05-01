/*
** EPITECH PROJECT, 2019
** inti_player
** File description:
** my_rpg
*/

#include "my_rpg.h"

player_t *init_player()
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (NULL);
    if (!(player->inventory = init_inventory()))
        return (NULL);
    player->move_x = 0;
    player->move_y = 0;
    player->up = 324;
    player->down = 0;
    player->left = 108;
    player->right = 216;
    return (player);
}
