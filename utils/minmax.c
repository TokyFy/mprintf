/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:27:54 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/09 16:27:54 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
