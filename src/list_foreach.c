#include "basic-types.h"

void    list_foreach(t_list *list, void (*f)(t_data))
{
    while (list)
    {
        f(list->data);
        list = list->next;
    }
}