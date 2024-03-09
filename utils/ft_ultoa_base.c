/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:28:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/09 16:28:29 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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
