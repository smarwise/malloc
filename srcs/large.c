#include "../includes/malloc.h"

void        *find_in_large(size_t size)
{
    block->large_head = block->large;
    while (block->large->next != NULL)
    {
        if (block->large->size >= size && block->large->free == 1)
        {
            block->large->free = 0;
            return (block->large->pointer);
        }
        block->large = block->large->next;
    }
    return (NULL);
}

void        *alloc_from_large(size_t size)
{
    void    *mem;

    if (!block->large)
    {
        block->large = (t_zone *)alloc(sizeof(t_block));
        block->large_head = block->large;
    }
    else
    {
        mem = find_in_large(size);
        if (mem == NULL)
        {
            block->large->next = (t_zone *)alloc(sizeof(t_block));
            block->large = block->large->next;
        }
        else
            return (mem);
    }
    block->large->pointer = alloc(size);
    block->large->free = 0;
    block->large->size = size;
    block->large->next = NULL;
    return (block->large->pointer);
}