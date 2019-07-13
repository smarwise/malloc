/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:01:19 by smarwise          #+#    #+#             */
/*   Updated: 2019/07/13 01:34:10 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*alloc(size_t size)
{
	void	*mem;
	
	mem = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
	return (mem);
}

void		init_alloc()
{
	int		size;
	int     num;
	
	block = alloc(sizeof(t_block));
	num = ((TINY * 100) / getpagesize()) + 1;
	size = (getpagesize() * num);
	block->tiny = alloc(size);
	num = ((LARGE * 100) / getpagesize()) + 1;
	size = (getpagesize() * num);
	block->small_mem = alloc(size);	
}

void		*malloc(size_t size)
{
	void	*memory;
	
	memory = NULL;
	if (!block)
		init_alloc();
	if (size < LARGE)
		memory = size <= TINY ? alloc_from_tiny(size) : alloc_from_small(size)
	else
		memory = alloc_from_large(size);
	return (memory);
}

int			main(void)
{
// 	char    *str1 = ft_malloc(25);
//     char    *str2 = ft_malloc(25);
//     char    *str3 = ft_malloc(90);
//     char    *str4 = ft_malloc(78);
//     char    *str5 = ft_malloc(550);
//     char    *str6 = ft_malloc(555);

//     block->tiny_allocs = block->tiny_head;
//     printf("tiny_address = %p small_adress = %p large_adress%p\n", block->tiny, block->small_mem, block->large);
//     printf("tiny_address = %p small_adress = %p large_adress = %p\n", block->tiny, block->small_mem, block->large);
//     int i = 0;
//     while (block->tiny_allocs)
//     {
//         printf("nb = %i, adress = %p, free? = %i, size = %lu\n", i, block->tiny_allocs->pointer, block->tiny_allocs->free, block->tiny_allocs->size);
//         block->tiny_allocs = block->tiny_allocs->next;
//         i++;
//     }
//     ft_strcpy(str1, "whats the deal with gir\n");
//     ft_strcpy(str2, "intentional\n");
//     printf("%p, %s%p, %s%p, %s%p, %s%p, %s%p, %s\n",  str1, str1, str2, str2, str3, str3, str4, str4, str5, str5, str6, str6);
//     block->tiny_allocs = block->tiny_head;
//     i = 0;
//     while (block->tiny_allocs)
//     {
//         printf("nb = %i, adress = %p, free? = %i, size = %lu\n", i, block->tiny_allocs->pointer, block->tiny_allocs->free, block->tiny_allocs->size);
//         block->tiny_allocs = block->tiny_allocs->next;
//         i++;
//     }
//     my_free(str5);
//     ft_malloc(512);
//     show_alloc_mem();
//     my_free(str1);
//     my_free(str2);
//     // sleep(30);
}
