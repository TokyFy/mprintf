#include "ft_printf.h"

int	ft_put_c(t_modifier *modifier, char chr)
{
	char	s[1] = " ";
	*s = chr;
 	if (!chr)
 	{
 	 	repeat(' ', modifier->with - 1);
 		return (max(modifier->with , 1));
 	}
	modifier->precision = (chr != 0);
	return ft_put_s(modifier, s);
}
