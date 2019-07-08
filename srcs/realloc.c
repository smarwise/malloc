#include "../includes/malloc.h"

void        throw_realloc_error(void    *ptr)
{
    printf("realloc: *** error for object %p: pointer being reallocated was not allocated\n", ptr);
}

void         *realloc_in_tiny(void *ptr, size_t new_size)
{
    if (!block->tiny_allocs)
        return (0);
    while (block->tiny_allocs->next != NULL)
    {
        if (block->tiny_allocs->pointer == ptr)
        {
            if (block->tiny_allocs->size > new_size)
                block->tiny_allocs->size = 0;
            else
            {
                if (block->tiny_allocs->next->pointer > (block->tiny_allocs->pointer + new_size + 32))
                {
                    block->tiny_allocs->size = new_size;
                    return (block->tiny_allocs->pointer);
                }
                else
                {
                    return(memcpy(ft_malloc(new_size), block->tiny_allocs->pointer, block->tiny_allocs->size));
                    my_free(block->tiny_allocs->pointer);
                }
            }
        }
        else
            block->tiny_allocs = block->tiny_allocs->next;
    }
    return (0);
}

void         *realloc_in_small(void *ptr, size_t new_size)
{
    if (!block->small)
        return (0);
    while (block->small->next != NULL)
    {
        if (block->small->pointer == ptr)
        {
            if (block->small->size > new_size)
                block->small->size = 0;
            else
            {
                if (block->small->next->pointer > (block->small->pointer + new_size + 32))
                {
                    block->small->size = new_size;
                    return (block->small->pointer);
                }
                else
                {
                    return(memcpy(ft_malloc(new_size), block->small->pointer, block->small->size));
                    my_free(block->small->pointer);
                }
            }
        }
        else
            block->small = block->small->next;
    }
    return (NULL);
}

void            *realloc_in_large(void *ptr, size_t new_size)
{
    if (!block->large)
        return (0);
    while (block->large->next != NULL)
    {
        if (block->large->pointer == ptr)
        {
           if (block->large->size > new_size)
                block->large->size = 0;
            else
            {
                if (block->large->next->pointer > (block->large->pointer + new_size + 32))
                {
                    block->large->size = new_size;
                    return (block->large->pointer);
                }
                else
                {
                    return(memcpy(ft_malloc(new_size), block->large->pointer, block->large->size));
                    my_free(block->large->pointer);
                }
            }
        }
        else
            block->large = block->large->next;
    }
    return (0);
}

int        if_exists(void *ptr)
{
    while (block->large->next != NULL)
    {
        if (block->large->pointer == ptr)
            return (0);
        else
            block->large = block->large->next;
    }
    while (block->small->next != NULL)
    {
        if (block->small->pointer == ptr)
            return (1);
        else
            block->small = block->small->next;
    }
    while (block->tiny_allocs->next != NULL)
    {
        if (block->tiny_allocs->pointer == ptr)
            return (2);
        else
            block->tiny_allocs = block->tiny_allocs->next;
    }
    return (3);
}

void    *my_realloc(void *ptr, size_t size)
{
    t_zone  temp;

    block->tiny_allocs = block->tiny_head;
    block->small = block->small_head;
    block->large = block->large_head;
    if (if_exists(ptr) == 0)
        return (realloc_in_large(ptr, size));
    else if (if_exists(ptr) == 1)
        return (realloc_in_small(ptr, size));
    else if (if_exists(ptr) == 2)
        return (realloc_in_tiny(ptr, size));
    else if (if_exists(ptr) == 3)
    {
        throw_realloc_error(ptr);
        return (NULL);
    }
    return (NULL);
}