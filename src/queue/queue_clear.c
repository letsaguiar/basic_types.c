#include "basic-types.h"
#include <stdlib.h>

void    queue_clear(t_queue *queue, void (*destroy)(t_data))
{
    if (!queue)
        return ;

    list_clear(&queue->head, destroy);
    free(queue);
}