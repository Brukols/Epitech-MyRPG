/*
** EPITECH PROJECT, 2019
** init_fight_text.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

texts_t *init_fight_text(void)
{
    texts_t *txt = malloc(sizeof(texts_t));

    if (txt == NULL)
        return (NULL);
    txt->type = FIGHT;
    txt->pos = init_vec2f(1170, 910);
    txt->text = sfText_create();
    txt->font = sfFont_createFromFile(FIGHT_FONT);
    if (txt->text == NULL || txt->font == NULL) {
        free(txt);
        return (NULL);
    }
    sfText_setCharacterSize(txt->text, 40);
    sfText_setFont(txt->text, txt->font);
    sfText_setPosition(txt->text, txt->pos);
    sfText_setColor(txt->text, sfWhite);
    sfText_setStyle(txt->text, sfTextBold);
    txt->next = NULL;
    txt->prev = NULL;
    return (txt);
}
