#include "../includes/malloc.h"

void        *alloc_from_tiny(size_t size)
{
    void    *prev_adress;
    size_t  prev_size;

    if (!block->tiny_allocs)
    {
        block->tiny_allocs = block->tiny;
        block->tiny_head = block->tiny_allocs;
    }
    else
    {
        while (block->tiny_allocs->next != NULL)
            block->tiny_allocs = block->tiny_allocs->next;
        prev_adress = block->tiny_allocs->pointer;
        prev_size = block->tiny_allocs->size;
        block->tiny_allocs->next = prev_adress + 4; //+ prev_size + 1;
        block->tiny_allocs = block->tiny_allocs->next;
    }
    block->tiny_allocs->size = size;
    block->tiny_allocs->free= 0;
    block->tiny_allocs->pointer = &block->tiny_allocs + sizeof(t_zone);
    block->tiny_allocs->next = NULL;
    return (block->tiny_allocs->pointer);
}   