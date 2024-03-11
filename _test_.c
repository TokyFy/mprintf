/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:23:23 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/09 15:23:23 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define _F "%d"
#define _A 255

int	main(void)
{
	int	ft;
	int	pr;

	ft = ft_printf(_F, _A);
	printf("|\n");
	pr = printf(_F, _A);
	printf("|\n");
	printf("\n%d | %d", ft, pr);
}
