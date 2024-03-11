/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:05:01 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/09 15:22:38 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include "stdlib.h"
# include <stdio.h>

typedef struct modifier
{
	int		minus;
	int		plus;
	int		hash;
	int		space;
	int		zero;
	int		with;
	int		precision;
}			t_modifier;

int			ft_printf(const char *format, ...);
int			ft_put_l(t_modifier *modifier, long nbr);
int			ft_put_u(t_modifier *modifier, long nbr);
int			ft_put_s(t_modifier *modifier, char *str);
int			ft_put_c(t_modifier *modifier, char chr);
int			ft_put_x_lower(t_modifier *modifier, long nbr);
int			ft_put_x_upper(t_modifier *modifier, long nbr);
int			ft_put_p(t_modifier *modifier, void *nbr);
int			ft_put_base(t_modifier *modifier, unsigned long nbr, char *base,
				char *sign);
int			is_flags(char c);
void		parse_flags(const char **format, t_modifier *modifier,
				va_list *args);
char		*ft_ltoa(long long i);
char		*ft_ltoa_base(long long i, char *base);
char		*ft_ultoa_base(unsigned long long i, char *base);
void		repeat(char c, int n);
long long	max(long long a, long long b);
long long	min(long long a, long long b);

#endif
