/*
** EPITECH PROJECT, 2019
** init_tex_player_house
** File description:
** my_rpg
*/

#include "my_rpg.h"

texts_t *init_texts_player_house(void)
{
    texts_t *texts = malloc(sizeof(texts_t));

    if (!texts)
        return (NULL);
    texts->prev = NULL;
    if (!(texts = init_box_text(texts)))
        return (NULL);
    return (texts);
}