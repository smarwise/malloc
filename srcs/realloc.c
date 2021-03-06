/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 01:34:45 by smarwise          #+#    #+#             */
/*   Updated: 2019/07/13 01:50:36 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		throw_realloc_error(void *ptr)
{
	char	*pointer;

	pointer = ft_tolower(ft_itoa_base((int)ptr, 16));
	ft_putstr("realloc: *** error for object 0x10");
	ft_putstr(pointer);
	ft_putstr(" : pointer being reallocated was not allocated\n");
	munmap(pointer, sizeof(pointer));
}

void		*realloc_in_tiny(void *ptr, size_t new_size)
{
	while (block->tiny_allocs)
	{
		if (block->tiny_allocs->pointer == ptr)
		{
			if (block->tiny_allocs->size > new_size)
			{
				block->tiny_allocs->size = new_size;
				return (block->tiny_allocs->pointer);
			}
			else
			{
				if (block->tiny_allocs->next != NULL)
				{
					if (block->tiny_allocs->next->pointer >
							(block->tiny_allocs->pointer + new_size + 32))
					{
						block->tiny_allocs->size = new_size;
						return (block->tiny_allocs->pointer);
					}
				}
				return (get_new_pointer(ptr, new_size));
			}
		}
		else
			block->tiny_allocs = block->tiny_allocs->next;
	}
	return (0);
}

void		*realloc_in_small(void *ptr, size_t new_size)
{
	while (block->small)
	{
		if (block->small->pointer == ptr)
		{
			if (block->small->size > new_size)
			{
				block->small->size = new_size;
				return (block->small->pointer);
			}
			else
			{
				if (block->small->next != NULL)
				{
					if (block->small->next->pointer >
							(block->small->pointer + new_size + 32))
					{
						block->small->size = new_size;
						return (block->small->pointer);
					}
				}
				return (get_new_pointer(ptr, new_size));
			}
		}
		else
			block->small = block->small->next;
	}
	return (NULL);
}

void		*realloc_in_large(void *ptr, size_t new_size)
{
	while (block->large)
	{
		if (block->large->pointer == ptr)
		{
			if (block->large->size > new_size)
			{
				block->large->size = new_size;
				return (block->large->pointer);
			}
			break ;
		}
		block->large = block->large->next;
	}
	return (get_new_pointer(ptr, new_size));
}

int			if_exists(void *ptr)
{
	while (block->large)
	{
		if (block->large->pointer == ptr)
			return (0);
		else
			block->large = block->large->next;
	}
	while (block->small)
	{
		if (block->small->pointer == ptr)
			return (1);
		else
			block->small = block->small->next;
	}
	while (block->tiny_allocs)
	{
		if (block->tiny_allocs->pointer == ptr)
			return (2);
		else
			block->tiny_allocs = block->tiny_allocs->next;
	}
	return (3);
}

void		*realloc(void *ptr, size_t size)
{
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
