#include "../includes/malloc.h"

void        *alloc_from_small(size_t size)
{
    void    *prev_adress;
    size_t  prev_size;

    if (!block->small)
    {
        block->small = (t_zone *)block->small_mem;
        block->small_head = block->small;
    }
    else
    {
        while (block->small->next != NULL)
            block->small = block->small->next;
        prev_adress = block->small->pointer;
        prev_size = block->small->size;
        block->small->next = (t_zone *)(prev_adress + prev_size + 1);
        block->small = block->small->next;
    }
    block->small->size = size;
    block->small->free= 0;
    block->small->pointer = (void *)block->small + sizeof(t_zone);
    block->small->next = NULL;
    return (block->small->pointer);
}