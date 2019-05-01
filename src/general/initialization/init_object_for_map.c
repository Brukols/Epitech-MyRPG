/*
** EPITECH PROJECT, 2019
** init_object_for_map
** File description:
** my_rpg
*/

#include "my_rpg.h"

char *next_data(char *str, int *i)
{
    int a = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!tmp)
        return (NULL);
    for (; str[*i] && str[*i] != ':'; a++, (*i)++)
        tmp[a] = str[*i];
    if (str[*i])
        *i += 1;
    tmp[a] = '\0';
    return (tmp);
}

game_object_t *init_object(game_object_t *go, char *str)
{
    int i = 0;
    char *tmp = next_data(str, &i);
    char *x = next_data(str, &i);
    char *y = next_data(str, &i);
    char *name[5] = {"shaft", "house_player", "brown_house", "rock", \
    "first_chest"};
    game_object_t *(*init_every_object[5])() = {init_shaft, init_house_player,\
    init_brown_house, init_rock, init_first_chest};

    if (!tmp || !x || !y)
        return (NULL);
    for (int i = 0; i < 5; i++) {
        if (!my_strcmp(tmp, name[i]))
            return (init_every_object[i](go, my_getnbr(x), my_getnbr(y)));
    }
    return (NULL);
}
