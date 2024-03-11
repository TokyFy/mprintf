/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:21:53 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/09 15:22:25 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	is_flags(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

void	parse_parameter(const char **format, t_modifier *modifier,
		va_list *args)
{
	(void)(args);
	while (is_flags(**format) && **format)
	{
		if (**format == '-')
			modifier->minus = 1;
		else if (**format == '+')
			modifier->plus = 1;
		else if (**format == ' ')
			modifier->space = 1;
		else if (**format == '#')
			modifier->hash = 1;
		else if (**format == '0')
			modifier->zero = 1;
		(*format)++;
	}
}

void	parse_width(const char **format, t_modifier *modifier, va_list *args)
{
	while (ft_isdigit(**format) && **format)
	{
		modifier->with = modifier->with * 10 + (**format - '0');
		(*format)++;
	}
	if (**format == '*')
	{
		modifier->with = va_arg(*args, int);
		if (modifier->with < 0)
		{
			modifier->minus = 1;
			modifier->with *= -1;
		}
		(*format)++;
	}
}

void	parse_precision(const char **format, t_modifier *modifier,
		va_list *args)
{
	if (**format == '.')
	{
		(*format)++;
		modifier->precision = 0;
		while (ft_isdigit(**format) && **format)
		{
			modifier->precision = modifier->precision * 10 + (**format - '0');
			(*format)++;
		}
		if (**format == '*')
		{
			modifier->precision = va_arg(*args, int);
			if (modifier->precision < 0)
				modifier->precision = -1;
			(*format)++;
		}
	}
}

void	parse_flags(const char **format, t_modifier *modifier, va_list *args)
{
	parse_parameter(format, modifier, args);
	parse_width(format, modifier, args);
	parse_precision(format, modifier, args);
}
