#include "ft_printf.h"
#include "libft/libft.h"

int	ft_put_c(t_modifier *modifier, char chr)
{
	char	s[1] = " ";
	*s = chr;
 	if (!chr)
 	{
    if(!modifier->minus)
 	 	    repeat(' ', modifier->with - 1);
    ft_putchar_fd('\0', 1);
    if(modifier->minus)
 	 	    repeat(' ', modifier->with - 1);
 		return (max(modifier->with , 1));
 	}
	modifier->precision = (chr != 0);
	return ft_put_s(modifier, s);
}
