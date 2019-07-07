#include "../includes/malloc.h"

void        *alloc_from_large(size_t size)
{
    if (!block->large)
    {
        block->large = alloc(sizeof(t_block));
        block->large_head = block->large;
        block->large->pointer = alloc(size);
        block->large->free = 0;
        block->large->size = size;
        block->large->next = NULL;
    }
    return (block->large->pointer);
}