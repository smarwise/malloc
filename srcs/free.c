#include "../includes/malloc.h"

void        throw_error(void    *ptr, int error)
{
    if (error == 0)
        printf("malloc: *** error for object %p: pointer being freed was not allocated\n", ptr);
    else
        printf("malloc: *** error for object %p: double free\n", ptr);
}

int         free_in_tiny(void *ptr)
{
    if (!block->tiny_allocs)
        return (0);
    while (block->tiny_allocs)
    {
        if (block->tiny_allocs->pointer == ptr)
        {
             if (block->tiny_allocs->free == 1)
                throw_error(ptr, 1);
            else
                block->tiny_allocs->free = 1;
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
    while (block->small)
    {
        if (block->small->pointer == ptr)
        {
            if (block->small->free == 1)
                throw_error(ptr, 1);
            else
                block->small->free = 1;
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
    printf("got here\n");
    while (block->large)
    {
        if (block->large->pointer == ptr)
        {
            if (block->large->free == 1)
                throw_error(ptr, 1);
            else
                block->large->free = 1;
            printf("got herewede\n");
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
        throw_error(ptr, 0);
    }
}