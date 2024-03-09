/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:24:00 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/09 15:24:00 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(t_modifier *modifier, long nbr)
{
	modifier->plus = 0;
	return (ft_put_l(modifier, (unsigned int)nbr));
}
