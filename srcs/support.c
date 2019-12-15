#include "../includes/malloc.h"

char		*ft_tolower(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= 'A' && c[i] <= 'Z')
			c[i] = c[i] + 32;
		i++;
	}
	return (c);
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int		numlen(int n, int base)
{
	int count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n)
	{
		n = n / base;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(u_int64_t value, int base)
{
	int		sign;
	long	nb;
	int		i;
	char	*str;
	int		len;

	sign = 0;
	i = 0;
	nb = (long)value;
	if (base == 10 && nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb < 0 && base == 10)
	{
		sign = 1;
		nb = nb * -1;
	}
	else if (nb < 0 && base != 10)
		nb = nb * -1;
	len = numlen(nb, base);
	str = (char *)ft_memalloc(sizeof(char) * (len + sign + 1));
	if (nb == 0)
		return ("0");
	len = len + sign;
	str[len] = '\0';
	len--;
	while (nb)
	{
		str[len] = (nb % base < 10) ? nb % base + '0' : nb % base - 10 + 65;
		nb = nb / base;
		len--;
	}
	if (sign == 1)
		str[len] = '-';
	return (str);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	if (n == 0 || s == d)
		return (d);
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}