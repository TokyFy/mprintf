/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:28:21 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/09 16:28:21 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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
