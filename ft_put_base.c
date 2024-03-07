#include "ft_printf.h"
#include "libft/libft.h"

void	x_handle_with(t_modifier *modifier, char *snbr, long nbr)
{
	char	padd;
  int l_s = ft_strlen(snbr);
	padd = ' ';
	modifier->with = max(modifier->with, modifier->precision);
	if (modifier->hash)
		modifier->with -= 2;
	if (modifier->zero && !modifier->minus && modifier->precision == -1)
	  	padd = '0';
  if(modifier->precision == 0 && nbr == 0)
    l_s = 0;
	repeat(padd, modifier->with - max(modifier->precision, l_s));
}

void	x_handle_precision(t_modifier *modifier, char *snbr)
{
	repeat('0', modifier->precision - ft_strlen(snbr));
}

void	x_sign_handler(t_modifier *modifier, char *sign , long nbr)
{
	if (modifier->hash && !(nbr == 0 && modifier->precision == 0))
		ft_putstr_fd(sign, 1);
}

int x_count(t_modifier *modifier , unsigned long nbr , char*s_nbr , char *sign)
{
  int count;
  if(modifier->with == 0  &&  modifier->precision == 0  &&  nbr == 0)
    return 0;
  count = max(modifier->with, max(modifier->precision, ft_strlen(s_nbr)));
  if(modifier->hash && !(modifier->precision == 0 && nbr == 0))
  {
    //if((max(modifier->with, modifier->precision) - ((long long)ft_strlen(s_nbr) + 2)) < 0)
    //  count += ft_strlen(sign);
    return max(modifier->with, max(modifier->precision, ft_strlen(s_nbr)+ft_strlen(sign)));
  }
  return count;
}


int	ft_put_base(t_modifier *modifier, unsigned long nbr, char *base, char *sign)
{
	char	*s;
	s = ft_ultoa_base(nbr, base);
  int count = x_count(modifier, nbr , s , sign);
	if (modifier->zero && modifier->precision == -1)
		x_sign_handler(modifier, sign , nbr);
	if (!modifier->minus)
		x_handle_with(modifier, s, nbr);
	if (!modifier->zero || modifier->precision != -1)
		x_sign_handler(modifier, sign , nbr);
	x_handle_precision(modifier, s);
	if (!(nbr == 0 && modifier->precision == 0))
		ft_putstr_fd(s, 1);
	if (modifier->minus)
	  x_handle_with(modifier, s, nbr);
 	return count;
}
