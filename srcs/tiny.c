/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 02:04:28 by smarwise          #+#    #+#             */
/*   Updated: 2019/07/13 02:07:02 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*alloc_from_tiny(size_t size)
{
	void	*prev_adress;
	size_t	prev_size;

	if (!block->tiny_allocs)
	{
		block->tiny_allocs = (t_zone *)block->tiny;
		block->tiny_head = block->tiny_allocs;
	}
	else
	{
		while (block->tiny_allocs->next != NULL)
			block->tiny_allocs = block->tiny_allocs->next;
		prev_adress = block->tiny_allocs->pointer;
		prev_size = block->tiny_allocs->size;
		block->tiny_allocs->next = (t_zone *)(prev_adress + prev_size + 1);
		block->tiny_allocs = block->tiny_allocs->next;
	}
	block->tiny_allocs->size = size;
	block->tiny_allocs->free = 0;
	block->tiny_allocs->pointer = (void *)block->tiny_allocs + sizeof(t_zone);
	block->tiny_allocs->next = NULL;
	return (block->tiny_allocs->pointer);
}
