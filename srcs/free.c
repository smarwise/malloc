#include "../includes/malloc.h"

void        throw_error(void    *ptr)
{
    printf("malloc: *** error for object %p: pointer being freed was not allocated\n", ptr);
}

int         free_in_tiny(void *ptr)
{
    if (!block->tiny_allocs)
        return (0);
    while (block->tiny_allocs->next != NULL)
    {
        if (block->tiny_allocs->pointer == ptr)
        {
            block->tiny_allocs->size = 0;
            block->tiny_allocs->free = 1;
            block->tiny_allocs->pointer = 0x0;
            return (1);
        }
        else
            block->tiny_allocs = block->tiny_allocs->next;
    }
    return (0);
}

int         free_in_small(void *ptr)
{
    if (!block->small)
        return (0);
    while (block->small->next != NULL)
    {
        if (block->small->pointer == ptr)
        {
            block->small->size = 0;
            block->small->free = 1;
            block->small->pointer = 0x0;
            return (1);
        }
        else
            block->small = block->small->next;
    }
    return (0);
}

int         free_in_large(void *ptr)
{
    if (!block->large)
        return (0);
    while (block->large->next != NULL)
    {
        if (block->large->pointer == ptr)
        {
            block->large->size = 0;
            block->large->free = 1;
            block->large->pointer = 0x0;
            return (1);
        }
        else
            block->large = block->large->next;
    }
    return (0);
}

void        my_free(void *ptr)
{
    block->tiny_allocs = block->tiny_head;
    block->small = block->small_head;
    block->large = block->large_head;
    if (free_in_large(ptr) == 1)
        return ;
    else if (free_in_small(ptr) == 1)
        return ;
    else if (free_in_tiny(ptr) == 1)
        return ;
    else
    {
        throw_error(ptr);
    }
}