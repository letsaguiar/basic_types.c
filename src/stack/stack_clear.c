#include "basic-types.h"
#include <stdlib.h>

void    stack_clear(t_stack *stack, void (*destroy)(t_data))
{
    list_clear(&stack->head, destroy);
    free(stack);
}