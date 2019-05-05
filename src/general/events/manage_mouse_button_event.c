/*
** EPITECH PROJECT, 2019
** mange__mouse_button_evenrt
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool touch_an_items(game_t *game, sfVector2f mouse)
{
    slot_t *slots = game->scenes->objs->player->inventory->slots;

    for (; slots && slots->item; slots = slots->next) {
        if (click(slots->pos, slots->size, mouse) == true) {
            slots->select = !slots->select;
            return (true);
        }
    }
    return (false);
}

int touch_a_button(game_t *game, sfVector2f mouse)
{
    buttons_t *buttons = game->scenes->buttons;
    int callback = 0;

    while (buttons->prev != NULL)
        buttons = buttons->prev;
    for (; buttons; buttons = buttons->next) {
        if (click(buttons->hitbox_pos, buttons->size, mouse) == true) {
<<<<<<< HEAD
            my_put_nbr(buttons->type);
            buttons->callback(game);
            return;
=======
            callback = buttons->callback(game);
>>>>>>> d96de1f4e7605f2215c8bb03209492d7f2f2f66e
        }
        if (callback == ERROR)
            return (ERROR);
        else if (buttons->type == ESCAPE && callback == 1)
            return (1);
    }
}

void manage_mouse_button_event(game_t *game)
{
    sfVector2i tmp_mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse = init_vec2f(tmp_mouse.x, tmp_mouse.y);

    if (game->scenes->scene == SETTINGS) {
        touch_a_button(game, mouse);
        return;
    }
    if (touch_an_items(game, mouse) == true)
        return;
    if (delete_an_item(game, mouse) == true)
        return;
    touch_a_button(game, mouse);
}
