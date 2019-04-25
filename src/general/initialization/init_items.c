/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_items
*/

#include "my_rpg.h"

void *create_item_with_id(int number)
{
    void(*tab_func[3]);

    tab_func[0] = create_sword;
    tab_func[1] = create_ring;
    tab_func[2] = NULL;
    return (tab_func[number]);
}

item_t *create_one_item(int id)
{
    item_t *(*pointeurOnFunction)(void);

    pointeurOnFunction = create_item_with_id(id);
    return (pointeurOnFunction());
}

item_t **init_items(void)
{
    int nb_id = 2;
    item_t **items = malloc(sizeof(item_t *) * (nb_id + 1));

    if (items == NULL)
        return (NULL);
    items[0] = create_one_item(0);
    items[1] = create_one_item(1);
    items[2] = NULL;
    for (int count = 0; count < nb_id; count++)
        if (items[count] == NULL)
            return (NULL);
    return (items);
}
