/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:01:19 by smarwise          #+#    #+#             */
/*   Updated: 2019/07/02 08:01:21 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void    *alloc(size)
{
    void *mem;

    mem = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    return (mem);
}

void        init_alloc()
{
    block = alloc(sizeof(t_block));
    block->tiny = alloc(64 * 100);
}

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
        block->tiny_allocs->next = prev_adress + prev_size + 1;
        block->tiny_allocs = block->tiny_allocs->next;
    }
    block->tiny_allocs->size = size;
    block->tiny_allocs->free= 0;
    block->tiny_allocs->pointer = &block->tiny_allocs + sizeof(t_zone);
    block->tiny_allocs->next = NULL;
    return (block->tiny_allocs->pointer);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         

void        *alloc_from_small(size_t size)
{
    void    *allocated_memory;

    allocated_memory = NULL;
    return (allocated_memory);
}

void        *ft_malloc(size_t size)
{
    void    *memory;

    memory = NULL;
    if (!block)
        init_alloc();
    if (size < LARGE)
        memory = size <= TINY ? alloc_from_tiny(size) : alloc_from_small(size);
    return (memory);
}

int         main(int argc, char **argv)
{
    char    *str = ft_malloc(25);
    char    *str1 = ft_malloc(25);
    char    *str2 = ft_malloc(25);

    printf("address = %p %p\n", block->tiny, block->tiny_head);
    str = "meh I dont know either like I really dont\n";
    str1 = "whats the deal with girls\n";
    str2 = "intentional\n";
    printf("%p, %s%p, %s%p %s", str, str, str1, str1, str2, str2);
}