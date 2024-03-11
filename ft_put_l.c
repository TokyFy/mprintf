/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:30:47 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/09 15:30:47 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

void	l_handle_with(t_modifier *modifier, char *snbr, long nbr)
{
	char	padd;

	padd = ' ';
	modifier->with = max(modifier->with, modifier->precision);
	if (nbr == 0 && modifier->precision == 0)
		modifier->with++;
	if (modifier->space || modifier->plus || nbr < 0)
		modifier->with--;
	if (modifier->zero && !modifier->minus && modifier->precision <= 0)
	{
		padd = '0';
	}
	if (modifier->precision == 0)
		padd = ' ';
	repeat(padd, modifier->with - max(modifier->precision, ft_strlen(snbr)));
}

void	l_handle_precision(t_modifier *modifier, char *snbr)
{
	repeat('0', modifier->precision - ft_strlen(snbr));
}

void	l_sign_handler(t_modifier *modifier, long nbr)
{
	if (nbr < 0)
		ft_putstr_fd("-", 1);
	else if (modifier->plus)
		ft_putstr_fd("+", 1);
	else if (modifier->space)
		ft_putstr_fd(" ", 1);
}

int	l_count(t_modifier *modifier, long nbr, char *s_sbr)
{
	int	l_s;
	int	has_sign;
	int	count;

	l_s = ft_strlen(s_sbr);
	has_sign = (modifier->plus || modifier->space || nbr < 0);
	count = max(max(modifier->with, modifier->precision), ft_strlen(s_sbr));
	if (modifier->precision == 0 && nbr == 0 && modifier->with == 0)
		count--;
	if (max(l_s, modifier->precision) >= modifier->with)
		count += has_sign;
	return (count);
}

int	ft_put_l(t_modifier *modifier, long nbr)
{
	char	*s;
	int		count;

	s = ft_ltoa(max(nbr, -nbr));
	count = l_count(modifier, nbr, s);
	if (modifier->zero && modifier->precision == -1)
		l_sign_handler(modifier, nbr);
	if (!modifier->minus)
		l_handle_with(modifier, s, nbr);
	if (!modifier->zero || modifier->precision != -1)
		l_sign_handler(modifier, nbr);
	l_handle_precision(modifier, s);
	if (!(nbr == 0 && modifier->precision == 0))
		ft_putstr_fd(s, 1);
	if (modifier->minus)
		l_handle_with(modifier, s, nbr);
	free(s);
	return (count);
}
