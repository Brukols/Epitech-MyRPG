/*
** EPITECH PROJECT, 2019
** player_basic_attack.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int player_basic_attack(game_t *game)
{
    texts_t *txt = game->scenes->texts;
    int attack_status = rand_action(5, 1);
    char *msg = "PLAYER attack: ";
    char *(*make_msg[3])(game_t *, char *) = {make_normal_attack_msg, \
        make_powerful_attack_msg, make_failed_attack_msg};

    msg = make_msg[attack_status](game, msg);
    if (msg == NULL)
        return (ERROR);
    calcul_basic_attack(attack_status, game);
    sfText_setString(txt->text, msg);
    return (0);
}

char *make_normal_attack_msg(game_t *game, char *msg)
{
    char *attack = nbr_to_str(game->scenes->objs->player->attack);

    if (attack == NULL)
        return (NULL);
    game->scenes->objs->player->attacking = true;
    msg = my_strdupcat(msg, "success!\nENEMY take ");
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, attack);
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, " damage.");
    if (msg == NULL)
        return (NULL);
    return (msg);
}

char *make_powerful_attack_msg(game_t *game, char *msg)
{
    char *attack = nbr_to_str(game->scenes->objs->player->attack * 2);

    if (attack == NULL)
        return (NULL);
    game->scenes->objs->player->attacking = true;
    msg = my_strdupcat(msg, "CRITICAL STRIKE!\nENEMY take ");
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, attack);
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, " damage.");
    if (msg == NULL)
        return (NULL);
    return (msg);
}

char *make_failed_attack_msg(game_t *game, char *msg)
{
    msg = my_strdupcat(msg, "it failed!");
    if (msg == NULL)
        return (NULL);
    return (msg);
}
