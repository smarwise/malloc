#include "../includes/malloc.h"

void    show_alloc_mem()
{
    printf("TINY : %p\n", block->tiny_head);
    if (!block->tiny_allocs)
    {
        block->tiny_allocs = block->tiny;
        block->tiny_head = block->tiny_allocs;
    }
}