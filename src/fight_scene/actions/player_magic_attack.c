/*
** EPITECH PROJECT, 2019
** player_attack.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int player_magic_attack(game_t *game)
{
    texts_t *txt = game->scenes->texts;
    int attack_status = rand_action(2, 1);
    char *msg = "PLAYER attack with MAGIC: ";

    if (is_enemy_dead(game))
        return (0);
    if (game->scenes->objs->player->hp == 0) {
        sfText_setString(txt->text, "You died !");
        return (0);
    }
    if (attack_status == 1 || attack_status == 0) {
        msg = make_magic_attack_msg(game, msg);
        if (msg == NULL)
            return (NULL);
    } else {
        msg = make_failed_attack_msg(game, msg);
        if (msg == NULL)
            return (NULL);
    }
    calcul_magic_attack(attack_status, game);
    sfText_setString(txt->text, msg);
    //animation;
    return (0);
}

char *make_magic_attack_msg(game_t *game, char *msg)
{
    char *power = nbr_to_str(game->scenes->objs->player->power);

    msg = my_strdupcat(msg, "success!\n ENEMY take ");
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, power);
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, " damage.");
    if (msg == NULL)
        return (NULL);
    return (msg);
}
