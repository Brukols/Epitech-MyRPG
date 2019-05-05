/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** interaction_with_chest
*/

#include "my_rpg.h"

void open_the_chest(game_t *game, game_object_t *go)
{
    musics_t *music = game->scenes->musics;
    slot_t *slot = game->scenes->objs->player->inventory->slots;
    inventory_t *inventory = game->scenes->objs->player->inventory;

    music_play(music, OPEN_CHEST_SOUND, sfFalse);
    remove_item(slot, 0);
    add_item(inventory, go->item);
    actualize_stats_player(game, go->item, 0.4);
    go->open = true;
    go->rect.top += 108;
    if (go->type == FIRST_CHEST) {
        game->quests->quest++;
        game->quests->all_quests = TRAINING;
    }
}

bool manage_chest(game_t *game, game_object_t *go)
{
    if (player_have_the_key(game->scenes->objs->player) == false)
        go->interaction = true;
    else
        open_the_chest(game, go);
    return (true);
}

bool interaction_with_chest(game_t *game)
{
    game_object_t *go = game->scenes->objs->game_object;
    player_t *player = game->scenes->objs->player;

    for (; go; go = go->next) {
        if (go->type != FIRST_CHEST || go->display == false)
            continue;
        if (go->open == true)
            continue;
        if (go->interaction == true) {
            change_quest(game, FIND_A_CHEST);
            go->interaction = false;
            return (false);
        }
        if (player_touch_chest(go, player->game_object) != true)
            continue;
        return (manage_chest(game, go));
    }
    return (false);
}