#include "basic-types.h"
#include <stdlib.h>

void    stack_clear(t_stack *stack, void (*destroy)(t_data))
{
    if (!stack)
        return ;

    list_clear(&stack->head, destroy);
    free(stack);
}