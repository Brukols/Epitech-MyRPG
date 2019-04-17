/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_discus
*/

#include "my_rpg.h"

char *next_discussion(char *str, int *i)
{
    int a = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!tmp)
        return (NULL);
    if (!str[*i])
        return (NULL);
    if (str[*i] == '[')
        *i += 1;
    if (str[*i] == '"')
        *i += 1;
    for (; str[*i] && str[*i] != '"'; (*i)++, a++)
        tmp[a] = str[*i];
    tmp[a] = '\0';
    if (str[*i])
        *i += 1;
    for (; str[*i] && str[*i] != '"'; (*i)++);
    return (tmp);
}

char **init_discuss(char *str, int *i)
{
    char *tmp;
    int a = 0;
    char **discuss = malloc(sizeof(char *));

    if (!discuss)
        return (NULL);
    discuss[0] = NULL;
    for (; (tmp = next_discussion(str, i)); a++) {
        if (!tmp)
            break;
        if (!(discuss = my_realloc_array(discuss, 1)))
            return (NULL);
        if (!(discuss[a] = my_strdup(tmp)))
            return (NULL);
        discuss[a + 1] = NULL;
    }
    return (discuss);
}