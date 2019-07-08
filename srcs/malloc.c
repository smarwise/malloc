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

void    *alloc(size_t size)
{
    void *mem;

    mem = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    return (mem);
}

void        init_alloc()
{
    block = alloc(sizeof(t_block));
    block->tiny = alloc(64 * 100);
    block->small_mem = alloc(512 * 100);
    
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      

void        *ft_malloc(size_t size)
{
    void    *memory;

    memory = NULL;
    if (!block)
        init_alloc();
    if (size < LARGE)
        memory = size <= TINY ? alloc_from_tiny(size) : alloc_from_small(size);
    else
        memory = alloc_from_large(size);
    return (memory);
}

int         main(int argc, char **argv)
{
    char    *str = ft_malloc(25);
    // char    *str1 = ft_malloc(80);
    // char    *str2 = ft_malloc(513);

    printf("address = %p %p %p\n", block->tiny, block->small_mem, block->large);
    // str = "meh I dont know either like I really dont\n";
    block->tiny_allocs = block->tiny_head;
    int i = 0;
    while (block->tiny_allocs->next)
    {
        printf("nb = %i, adress = %p, free? = %i, size = %lu", i, block->tiny_allocs->pointer, block->tiny_allocs->free, block->tiny_allocs->size);
        block->tiny_allocs = block->tiny_allocs->next;
        i++;
    }
    printf("%p", str);
    my_free(str);
    while (block->tiny_allocs->next)
    {
        printf("nb = %i, adress = %p, free? = %i, size = %lu", i, block->tiny_allocs->pointer, block->tiny_allocs->free, block->tiny_allocs->size);
        block->tiny_allocs = block->tiny_allocs->next;
        i++;
    }
    // str1 = "whats the deal with girls\n";
    // str2 = "intentional\n";
    // printf("%p, %s%p, %s%p, %s", str, str);//, str1, str1, str2, str2);
}