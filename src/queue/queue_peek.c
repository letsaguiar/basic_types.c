#include "basic-types.h"
#include <stdlib.h>

t_data  queue_peek(t_queue *queue)
{
    if (!queue || !queue->head)
        return (NULL);

    return (queue->head->data);
}