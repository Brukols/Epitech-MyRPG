/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inti_texts
*/

#include "my_rpg.h"

texts_t *init_box_text(texts_t *texts)
{
    for (int i = 0; i < 2; i++) {
        if (!(texts->text = sfText_create()))
            return (NULL);
        if (!(texts->font = sfFont_createFromFile(\
            "ressources/font/neuropol.ttf")))
            return (NULL);
        texts->type = (!i ? NAME_BOX : TEXT_BOX);
        texts->pos = (!i ? init_vec2f(590, 720) : init_vec2f(430, 810));
        if (i == 1)
            break;
        if (!(texts->next = malloc(sizeof(texts_t))))
            return (NULL);
        texts->next->prev = texts;
        texts = texts->next;
    }
    texts->next = NULL;
    texts = texts->prev;
    return (texts);
}