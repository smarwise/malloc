#include "../includes/malloc.h"

void        *get_new_pointer(void *ptr, size_t size)
{
    void     *mem;

    mem = ft_memcpy(malloc(size), block->tiny_allocs->pointer, block->tiny_allocs->size);
    (void)ptr;
    // free(ptr);
    return (mem);
}