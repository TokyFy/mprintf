#include "ft_printf.h"
#include "libft/libft.h"

void	x_handle_with(t_modifier *modifier, char *snbr, long nbr)
{
	char	padd;

	padd = ' ';
	modifier->with = max(modifier->with, modifier->precision);
	if (nbr == 0 && modifier->precision == 0)
		modifier->with++;
	if (modifier->hash)
		modifier->with -= 2;
	if (modifier->zero && !modifier->minus && modifier->precision == -1)
		padd = '0';
	repeat(padd, modifier->with - max(modifier->precision, ft_strlen(snbr)));
}

void	x_handle_precision(t_modifier *modifier, char *snbr)
{
	repeat('0', modifier->precision - ft_strlen(snbr));
}

void	x_sign_handler(t_modifier *modifier, char *sign)
{
	if (modifier->hash)
		ft_putstr_fd(sign, 1);
}

int	ft_put_base(t_modifier *modifier, unsigned long nbr, char *base, char *sign)
{
	char	*s;

	s = ft_ultoa_base(nbr, base);
  int l_s = ft_strlen(s);
	if (modifier->zero && modifier->precision == -1)
		x_sign_handler(modifier, sign);
	if (!modifier->minus)
		x_handle_with(modifier, s, nbr);
	if (!modifier->zero || modifier->precision != -1)
		x_sign_handler(modifier, sign);
	x_handle_precision(modifier, s);
	if (!(nbr == 0 && modifier->precision == 0))
		ft_putstr_fd(s, 1);
	if (modifier->minus)
	  x_handle_with(modifier, s, nbr);
  if(modifier->hash)
    return max(modifier->with, l_s) + ft_strlen(sign);
	return (max(modifier->with, l_s));
}
