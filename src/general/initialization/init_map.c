/*
** EPITECH PROJECT, 2019
** init_map.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

char **init_map(char *path)
{
    FILE *fd = fopen(path, "r");
    char **result = malloc(sizeof(char *) * 1);
    char *str = NULL;
    size_t size = 1;
    int i = 0;

    if (!fd || !result)
        return (NULL);
    result[0] = NULL;
    while (getline(&str, &size, fd) != -1) {
        if (str[my_strlen(str) - 1] == '\n')
            str[my_strlen(str) - 1] = '\0';
        result = my_realloc_array(result, 1);
        result[i] = my_strdup(str);
        i++;
        result[i] = NULL;
    }
    if (fclose(fd) != 0)
        return (NULL);
    return (result);
}
