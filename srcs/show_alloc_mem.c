/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarwise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 01:51:47 by smarwise          #+#    #+#             */
/*   Updated: 2019/07/13 02:00:44 by smarwise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		print_some(void *ptr, char *str)
{
	ft_putstr(str);
	ft_putstr("   : 0x");
	ft_putendl(ft_tolower(ft_itoa_base((int)ptr, 16)));
}

size_t		show_tiny(void)
{
	size_t	sum;

	sum = 0;
	block->tiny_allocs = block->tiny_head;
	while (block->tiny_allocs)
	{
		ft_putstr("0x");
		ft_putstr(ft_tolower(ft_itoa_base((int)block->tiny_allocs->pointer,
						16)));
		ft_putstr(" - 0x");
		ft_putstr(ft_tolower(ft_itoa_base((int)block->tiny_allocs->pointer
						+ block->tiny_allocs->size, 16)));
		ft_putstr(" : ");
		ft_putnbr(block->tiny_allocs->size);
		ft_putendl(" bytes");
		sum += block->tiny_allocs->size;
		block->tiny_allocs = block->tiny_allocs->next;
	}
	return (sum);
}

size_t		show_small(void)
{
	size_t	sum;

	sum = 0;
	block->small = block->small_head;
	while (block->small)
	{
		ft_putstr("0x");
		ft_putstr(ft_tolower(ft_itoa_base((int)block->small->pointer, 16)));
		ft_putstr(" - 0x");
		ft_putstr(ft_tolower(ft_itoa_base((int)block->small->pointer
						+ block->small->size, 16)));
		ft_putstr(" : ");
		ft_putnbr(block->small->size);
		ft_putendl(" bytes");
		sum += block->small->size;
		block->small = block->small->next;
	}
	return (sum);
}

size_t		show_large(void)
{
	size_t	sum;

	sum = 0;
	block->large = block->large_head;
	while (block->large)
	{
		ft_putstr("0x");
		ft_putstr(ft_tolower(ft_itoa_base((int)block->large->pointer, 16)));
		ft_putstr(" - 0x");
		ft_putstr(ft_tolower(ft_itoa_base((int)block->large->pointer +
						block->large->size, 16)));
		ft_putstr(" : ");
		ft_putnbr(block->large->size);
		ft_putendl(" bytes");
		sum += block->large->size;
		block->large = block->large->next;
	}
	return (sum);
}

void		show_alloc_mem(void)
{
	size_t	sum;

	sum = 0;
	block->tiny_allocs = block->tiny_head;
	block->small = block->small_head;
	block->large = block->large_head;
	print_some(block->tiny_head, "TINY");
	if (!block->tiny_allocs)
		sum += 0;
	else
		sum += show_tiny();
	print_some(block->small_head, "SMALL");
	if (!block->small)
		sum += 0;
	else
		sum += show_small();
	print_some(block->large_head, "LARGE");
	if (!block->large)
		sum += 0;
	else
		sum += show_large();
	ft_putstr("Total  : ");
	ft_putnbr(sum);
	ft_putendl(" bytes");
}
