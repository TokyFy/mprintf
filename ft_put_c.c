#include "ft_printf.h"

int	ft_put_c(t_modifier *modifier, char chr)
{
	char	s[1] = " ";

	*s = chr;
// 	if (!chr)
// 	{
// 		if (!modifier->minus)
// 			repeat(' ', modifier->with - 1);
// 		return (-1);
// 	}
	modifier->precision = 1;
	return (ft_put_s(modifier, s));
}
