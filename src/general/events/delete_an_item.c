/*
** EPITECH PROJECT, 2019
** dleete_an_item
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool touch_the_trash(game_t *game, slot_t *slot, sfVector2f mouse, int i)
{
    slot_t *slots = game->scenes->objs->player->inventory->slots;
    sfVector2f pos_trash = init_vec2f(slot->pos.x + 468, slot->pos.y - 120);
    sfVector2f size_trash = init_vec2f(41, 40);

    if (click(pos_trash, size_trash, mouse) == true)
        remove_item(slots, i);
    return (true);
}

bool delete_an_item(game_t *game, sfVector2f mouse)
{
    slot_t *slots = game->scenes->objs->player->inventory->slots;

    for (int i = 0; slots && slots->item; slots = slots->next) {
        if (slots->select == true)
            return (touch_the_trash(game, slots, mouse, i));
        i++;
    }
    return (false);
}