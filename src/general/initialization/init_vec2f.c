/*
** EPITECH PROJECT, 2019
** init_vec
** File description:
** defened
*/

#include "my_rpg.h"

sfVector2f init_vec2f(float x, float y)
{
    sfVector2f pos = {x, y};

    return (pos);
}

sfIntRect init_intrect(int left, int top, int width, int height)
{
    sfIntRect rect = {left, top, width, height};

    return (rect);
}
