#include "../includes/malloc.h"

void        *alloc_from_large(size_t size)
{
    if (!block->large)
    {
        block->large = (t_zone *)alloc(sizeof(t_block));
        block->large_head = block->large;
    }
    else
    {
        while (block->large->next != NULL)
        {
            if (block->large->size >= size && block->large->free == 1)
            {
                block->large->free = 0;
                return (block->large->pointer);
            }
            block->large = block->large->next;
        }
        block->large->next = (t_zone *)alloc(sizeof(t_block));
        block->large = block->large->next;
    }
    block->large->pointer = alloc(size);
    block->large->free = 0;
    block->large->size = size;
    block->large->next = NULL;
    return (block->large->pointer);
}