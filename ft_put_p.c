/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:24:59 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/09 15:24:59 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_p(t_modifier *modifier, void *ptr)
{
	long long	nbr;

	nbr = (long long)ptr;
	if (!nbr)
	{
		if (modifier->precision < 5)
			modifier->precision = -1;
		return (ft_put_s(modifier, "(nil)"));
	}
	modifier->hash = 1;
	return (ft_put_base(modifier, nbr, "0123456789abcdef", "0x"));
}
