#include "basic-types.h"

int list_append(t_list **list, t_data data)
{
    t_list *new = list_create(data);
    if (!new)
        return (0);

    t_list *last = list_last(*list);
    if (!last)
        *list = new;
    else
        last->next = new;
    
    return (1);
}