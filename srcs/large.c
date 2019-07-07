#include "../includes/malloc.h"

void        *alloc_from_large(size_t size)
{
    if (!block->large)
    {
        block->large = alloc(sizeof(t_block));
        block->large->pointer = alloc(size);

        block->large->next = NULL;
    }
}