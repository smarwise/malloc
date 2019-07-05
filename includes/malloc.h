#ifndef MALLOC_H
#define MALLOC_H

#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/mman.h>
#include <stdio.h>
#define TINY 64
#define LARGE 512

typedef struct  	s_zone
{
	size_t 			size;
	struct s_zone	*next;
	void			*pointer;
	int				free;
}					t_zone;


typedef struct  	s_block
{
	size_t 			size;
	struct s_block	*next;
	t_zone			*tiny_allocs;
	t_zone			*small;
	t_zone			*large;
	void			*tiny;
	t_zone			*tiny_head;
}					t_block;

t_block				*block;
void				show_alloc_mem();
#endif