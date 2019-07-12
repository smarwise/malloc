#include "../includes/malloc.h"

void    show_alloc_mem()
{
    if (!block->tiny_allocs)
    {
        block->tiny_allocs = block->tiny;
        block->tiny_head = block->tiny_allocs;
    }
}