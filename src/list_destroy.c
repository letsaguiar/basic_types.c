#include "basic-types.h"
#include <stdlib.h>

void    list_destroy(t_list *list, void (*destroy)(t_data))
{
    if (list)
    {
        if (destroy)
            destroy(list->data);
        free(list);
    }
}