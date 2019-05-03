/*
** EPITECH PROJECT, 2019
** init_what_texture
** File description:
** my_rg
*/

#include "my_rpg.h"

char *init_what_texture(char *str, int *i)
{
    char *next = next_for_pnj(str, i);

    if (!next)
        return (NULL);
    if (next[0] == '1')
        return (my_strdup("ressources/sprites/chara5.png"));
    if (next[0] == '2')
        return (my_strdup("ressources/sprites/chara4.png"));
    return (NULL);
}