/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my_rpg.h"
#include <stdio.h>

int main(void)
{
    sfRenderWindow *win = create_window(1920, 1080, 60);
    scene_t *fight = init_fight_scene();

    if (win == NULL || fight == NULL)
        return (ERROR);
    while (sfRenderWindow_isOpen(win)) {
        display_fight_scene(win, fight);
        sfRenderWindow_display(win);
        sfRenderWindow_clear(win, sfBlack);
    }
    sfRenderWindow_close(win);
    return (0);
}
