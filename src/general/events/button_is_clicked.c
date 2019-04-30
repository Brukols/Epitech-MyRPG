/*
** EPITECH PROJECT, 2019
** button_is_clicked
** File description:
** defedner
*/

#include "my_rpg.h"

bool click(sfVector2f pos, sfVector2f size, sfVector2f mouse)
{
    if (mouse.x > pos.x && mouse.x < pos.x + size.x) {
        if (mouse.y > pos.y && mouse.y < pos.y + size.y)
            return (true);
    }
    return (false);
}
