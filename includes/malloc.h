#ifndef MALLOC_H
#define MALLOC_H

#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
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
	void			*small_mem;
	t_zone			*tiny_head;
	t_zone			*small_head;
	t_zone			*large_head;
}					t_block;

t_block				*block;
void				show_alloc_mem();
void				*alloc_from_tiny(size_t size);
void				*alloc_from_small(size_t size);
void				*alloc(size_t size);
void        		*alloc_from_large(size_t size);
void        		my_free(void *ptr);
void    			*my_realloc(void *ptr, size_t size);
void       			*ft_malloc(size_t size);
void				*get_new_pointer(void *ptr, size_t size);
char				*ft_tolower(char *c);
void				ft_putstr(char const *s);
char				*ft_itoa_base(u_int64_t value, int base);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				*ft_memalloc(size_t size);
char				*ft_strdup(const char *src);
void				ft_putchar(char c);
size_t				ft_strlen(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcpy(char *s1, const char *s2);
#endif