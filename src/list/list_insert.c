#include "basic-types.h"

int list_insert(t_list **list, t_data data, int index, void (*destroy)(t_data))
{
    t_list *new = list_create(data);
    if (!new)
        return (0);

    if (index == 0)
    {
        new->next = *list;
        *list = new;
        return (1);
    }

    t_list *tmp = list_get(*list, index - 1);
    if (!tmp)
    {
        list_destroy(new, destroy);
        return (0);
    }

    new->next = tmp->next;
    tmp->next = new;
    return (1);
}