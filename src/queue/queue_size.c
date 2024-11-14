#include "basic-types.h"
#include <stdlib.h>

int queue_size(t_queue *queue)
{
    if (!queue || !queue->head)
        return (0);

    return (list_size(queue->head));
}