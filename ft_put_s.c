#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

void	s_handle_width(t_modifier *modifier, char *str)
{
	if (!modifier->minus)
		repeat(' ', modifier->with - ft_strlen(str));
	modifier->minus = !modifier->minus;
}

int	ft_put_s(t_modifier *modifier, char *str)
{
	char	*s;
	if (!str)
	{
		if (modifier->precision != -1 && modifier->precision < 6)
			modifier->precision = 0;
		return ft_put_s(modifier, "(null)");
	}
  s = ft_substr(str, 0, min(modifier->precision, ft_strlen(str)));
  t_size_t l_s = ft_strlen(s);
	s_handle_width(modifier, s);
	ft_putstr_fd(s, 1);
	s_handle_width(modifier, s);
	free(s);
	return (max(modifier->with, l_s));
}
