#include "../includes/malloc.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (src[i])
		i++;
	i++;
	dest = (char *)malloc(sizeof(char) * i);
	if (dest == NULL)
		return (NULL);
	while (n < i)
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

void		*ft_memalloc(size_t size)
{
	void	*freshmem;

	// freshmem = (void *)mmap(freshmem, sizeof(void) * size, );
    freshmem = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
	if (freshmem == NULL)
		return (NULL);
	ft_bzero(freshmem, size);
	return (freshmem);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*be;

	be = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		be[i] = c;
		i++;
	}
	return (be);
}
