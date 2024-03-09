/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:28:09 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/09 16:28:09 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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
