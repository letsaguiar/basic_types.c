#include "basic-types.h"

void    list_foreach(t_list *list, void (*f)(t_data, int))
{
    int i = 0;
    while (list)
    {
        f(list->data, i);
        
        list = list->next;
        i += 1;
    }
}