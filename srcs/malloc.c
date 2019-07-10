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

int         main(void)
{
    char    *str = ft_malloc(25);
    char    *str1 = ft_malloc(35);
    char    *str2 = ft_malloc(25);
    char    *str3 = ft_malloc(65);
    char    *str4 = ft_malloc(70);
    char    *str5 = ft_malloc(75);
    char    *str6 = ft_malloc(513);
    char    *str7 = ft_malloc(514);
    char    *str8 = ft_malloc(515);

    int i = 0;
    ft_strcpy(str,  "meh I dont know\n");
    ft_strcpy(str1, "whats the devf\n");
    ft_strcpy(str2, "intentional\n");
    ft_strcpy(str3,  "test small 1\n");
    ft_strcpy(str4, "test small 2\n");
    ft_strcpy(str5, "test small 3\n");
    ft_strcpy(str6,  "test large 1\n");
    ft_strcpy(str7, "test large 2\n");
    ft_strcpy(str8, "test large 3\n");
    printf("%p, %s%p, %s%p, %s%p, %s%p, %s%p, %s%p, %s%p, %s%p, %s", str, str, str1, str1, str2, str2, str3, str3, str4, str4, str5, str5, str6, str6, str7, str7, str8, str8);
    block->tiny_allocs = block->tiny_head;
    block->small = block->small_head;
    block->large = block->large_head;
    i = 0;
    while (block->tiny_allocs)
    {
        printf("nb = %i, adress = %p, free? = %i, size = %lu\n", i, block->tiny_allocs->pointer, block->tiny_allocs->free, block->tiny_allocs->size);
        block->tiny_allocs = block->tiny_allocs->next;
        i++;
    }
    i = 0;
    while (block->small)
    {
        printf("nb = %i, adress = %p, free? = %i, size = %lu\n", i, block->small->pointer, block->small->free, block->small->size);
        block->small = block->small->next;
        i++;
    }
    i = 0;
    while (block->large)
    {
        printf("nb = %i, adress = %p, free? = %i, size = %lu\n", i, block->large->pointer, block->large->free, block->large->size);
        block->large = block->large->next;
        i++;
    }
    my_free(str);
    my_free(str3);
    my_free(str8);
    block->tiny_allocs = block->tiny_head;
    block->small = block->small_head;
    block->large = block->large_head;
    i = 0;
    while (block->tiny_allocs)
    {
        printf("nb = %i, adress = %p, free? = %i, size = %lu\n", i, block->tiny_allocs->pointer, block->tiny_allocs->free, block->tiny_allocs->size);
        block->tiny_allocs = block->tiny_allocs->next;
        i++;
    }
    i = 0;
    while (block->small)
    {
        printf("nb = %i, adress = %p, free? = %i, size = %lu\n", i, block->small->pointer, block->small->free, block->small->size);
        block->small = block->small->next;
        i++;
    }
    i = 0;
    while (block->large)
    {
        printf("nb = %i, adress = %p, free? = %i, size = %lu\n", i, block->large->pointer, block->large->free, block->large->size);
        block->large = block->large->next;
        i++;
    }
}