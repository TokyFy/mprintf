/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:30:24 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/09 15:30:24 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_x_lower(t_modifier *modifier, long nbr)
{
	return (ft_put_base(modifier, (unsigned long)nbr, "0123456789abcdef",
			"0x"));
}

int	ft_put_x_upper(t_modifier *modifier, long nbr)
{
	return (ft_put_base(modifier, (unsigned long)nbr, "0123456789ABCDEF",
			"0X"));
}
