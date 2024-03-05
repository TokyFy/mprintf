#include "libft/libft.h"

void	repeat(char c, int n)
{
	while (n-- > 0)
	{
		ft_putchar_fd(c, 1);
	}
}

long long	max(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}

long long	min(long long a, long long b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	count_digit_dec(long n)
{
	if (n < 0)
		return (1 + count_digit_dec(-n));
	if (n <= 9)
		return (1);
	return (1 + count_digit_dec(n / 10));
}

char	*ft_ltoa(long i)
{
	long	n;
	int		digit;
	char	*str;

	n = i;
	digit = count_digit_dec(n);
	str = 0;
	str = ft_calloc(digit + 1, sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
		n = -n;
	while (digit > 0)
	{
		*(str + digit - 1) = (n % 10) + '0';
		n = n / 10;
		digit--;
	}
	if (i < 0)
		*str = '-';
	return (str);
}

static int	count_digit_base(long long n, int base)
{
	if (n < 0)
		return (1 + count_digit_base(-n, base));
	if (n < base)
		return (1);
	return (1 + count_digit_base(n / base, base));
}

char	*ft_ltoa_base(long long i, char *base)
{
	long long	n;
	int			digit;
	char		*str;
	int			nbase;

	nbase = ft_strlen(base);
	n = i;
	digit = count_digit_base(n, nbase);
	str = 0;
	str = ft_calloc(digit + 1, sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
		n = -n;
	while (digit > 0)
	{
		*(str + digit - 1) = base[(n % 16)];
		n = n / nbase;
		digit--;
	}
	if (i < 0)
		*str = '-';
	return (str);
}

static int	ul_count_digit_base(unsigned long long n, int base)
{
	if (n < (unsigned long long)base)
		return (1);
	return (1 + ul_count_digit_base(n / base, base));
}

char	*ft_ultoa_base(unsigned long long i, char *base)
{
	unsigned long long	n;
	int					digit;
	char				*str;
	int					nbase;

	nbase = ft_strlen(base);
	n = i;
	digit = ul_count_digit_base(n, nbase);
	str = 0;
	str = ft_calloc(digit + 1, sizeof(char));
	if (!str)
		return (0);
	while (digit > 0)
	{
		*(str + digit - 1) = base[(n % 16)];
		n = n / nbase;
		digit--;
	}
	return (str);
}
