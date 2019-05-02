/*
** EPITECH PROJECT, 2019
** my_put_pixel
** File description:
** my_rpg
*/

#include "my_rpg.h"

void my_put_pixel(framebuffer_t *frame, int y, int x, sfColor color)
{
    if (y < frame->height && x < frame->width && y >= 0 && x >= 0) {
        frame->pixels[(frame->width * y + x) * 4] = color.r;
        frame->pixels[(frame->width * y + x) * 4 + 1] = color.g;
        frame->pixels[(frame->width * y + x) * 4 + 2] = color.b;
        frame->pixels[(frame->width * y + x) * 4 + 3] = color.a;
    }
}