#include "../includes/malloc.h"

void	ft_putendl(char const *s)
{
	int i;
	int n;

	if (!s)
		return ;
	i = 0;
	n = ft_strlen(s);
	write(1, &s[i++], n);
	write(1, "\n", 1);
}

void	ft_putnbr(int n)
{
	char c;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		c = '0' + (n % 10);
		write(1, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}