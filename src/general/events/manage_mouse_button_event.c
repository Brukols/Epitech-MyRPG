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

void touch_a_button(game_t *game, sfVector2f mouse)
{
    buttons_t *buttons = game->scenes->buttons;

    for (; buttons; buttons = buttons->next) {
        if (click(buttons->hitbox_pos, buttons->size, mouse) == true) {
            buttons->callback(game);
            return;
        }
    }
}

void manage_mouse_button_event(game_t *game)
{
    sfVector2i tmp_mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse = init_vec2f(tmp_mouse.x, tmp_mouse.y);

    if (touch_an_items(game, mouse) == true)
        return;
    if (delete_an_item(game, mouse) == true)
        return;
    touch_a_button(game, mouse);
}
