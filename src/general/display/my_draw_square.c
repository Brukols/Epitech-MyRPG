/*
** EPITECH PROJECT, 2019
** my_drawswquare
** File description:
** my_rpg
*/

#include "my_rpg.h"

void my_draw_square(framebuffer_t *frame, all_particle_t *all, int size)
{
    int tmp_y = all->y;
    int tmp_x = all->x;

    for (int i = 0; i < size; i++, tmp_y++) {
        tmp_x = all->x;
        for (int a = 0; a < size; a++, tmp_x++)
            my_put_pixel(frame, tmp_y, tmp_x, all->color);
    }
}