/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 01:23:18 by smarwise          #+#    #+#             */
/*   Updated: 2019/07/13 02:09:28 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*get_new_pointer(void *ptr, size_t size)
{
	void	*mem;

	mem = ft_memcpy(malloc(size), block->tiny_allocs->pointer,
			block->tiny_allocs->size);
	(void)ptr;
	return (mem);
}
