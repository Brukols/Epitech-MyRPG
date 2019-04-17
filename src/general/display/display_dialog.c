/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_dialog
*/

#include "my_rpg.h"

void display_pnj_name(game_t *game, texts_t *texts, pnj_t *pnj)
{
    sfText_setCharacterSize(texts->text, 50);
    sfText_setFont(texts->text, texts->font);
    sfText_setPosition(texts->text, texts->pos);
    sfText_setColor(texts->text, sfRed);
    sfText_setString(texts->text, pnj->name);
    sfRenderWindow_drawText(game->window, texts->text, NULL);
}

void display_pnj_dialog(game_t *game, texts_t *texts, pnj_t *pnj)
{
    sfText_setCharacterSize(texts->text, 50);
    sfText_setFont(texts->text, texts->font);
    sfText_setPosition(texts->text, texts->pos);
    sfText_setColor(texts->text, sfBlack);
    sfText_setString(texts->text, pnj->discuss[pnj->next_dialog]);
    sfRenderWindow_drawText(game->window, texts->text, NULL);
}