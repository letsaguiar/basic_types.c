#include "basic-types.h"
#include <stdlib.h>

void    queue_clear(t_queue *queue, void (*destroy)(t_data))
{
    list_clear(&queue->head, destroy);
    free(queue);
}