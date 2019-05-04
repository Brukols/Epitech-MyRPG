/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display_fight_characters
*/

#include "my_rpg.h"

void display_fight_characters(game_t *game)
{
    static enemies_t **enemies = NULL;
    int nb = game->scenes->quest;

    if (enemies == NULL)
        init_enemies(enemies, nb);
        
}
