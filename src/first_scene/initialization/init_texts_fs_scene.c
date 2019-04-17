/*
** EPITECH PROJECT, 2019
** my_rp
** File description:
** init_texts_fs_scenes
*/

#include "my_rpg.h"

texts_t *init_texts_fs_scene(void)
{
    texts_t *texts = malloc(sizeof(texts_t));

    if (!texts)
        return (NULL);
    texts->prev = NULL;
    if (!(texts = init_box_text(texts)))
        return (NULL);
    return (texts);
}