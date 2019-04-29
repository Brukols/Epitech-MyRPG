/*
** EPITECH PROJECT, 2019
** display_msg_in_box
** File description:
** my_rpg
*/

#include "my_rpg.h"

void display_msg_in_box(game_t *game, char *str)
{
    texts_t *texts = game->scenes->texts;

    for (; texts->type != TEXT_BOX; texts = texts->next);
    sfText_setCharacterSize(texts->text, 40);
    sfText_setFont(texts->text, texts->font);
    sfText_setPosition(texts->text, texts->pos);
    sfText_setColor(texts->text, sfBlack);
    sfText_setString(texts->text, str);
    sfRenderWindow_drawText(game->window, texts->text, NULL);
}