#include "ft_printf.h"
#include "libft/libft.h"

void l_handle_with(t_modifier *modifier , char *snbr , long nbr)
{
   char padd = ' ';
   modifier->with = max(modifier->with , modifier->precision);

   if(nbr == 0 && modifier->precision == 0)
     modifier->with++;  

   if(modifier->space || modifier->plus ||  nbr < 0)
    modifier->with--;
   
   if(modifier->zero && !modifier->minus && modifier->precision <= 0)
    padd = '0';

   repeat(padd, modifier->with - max(modifier->precision , ft_strlen(snbr)));
}

void l_handle_precision(t_modifier *modifier , char *snbr)
{
    repeat('0', modifier->precision - ft_strlen(snbr));
}

void l_sign_handler(t_modifier *modifier , long nbr)
{
   if(nbr < 0)
  ft_putstr_fd("-", 1);
   else if (modifier->plus)
     ft_putstr_fd("+", 1);
   else if (modifier->space)
     ft_putstr_fd(" ", 1);
}

int ft_put_l(t_modifier *modifier , long nbr)
{
  char *s = ft_ltoa(max(nbr, -nbr));
  if(modifier->zero && modifier->precision == -1)
    l_sign_handler(modifier, nbr);
  if(!modifier->minus)
    l_handle_with(modifier, s , nbr);
  if(!modifier->zero || modifier->precision != -1)
    l_sign_handler(modifier, nbr);
  l_handle_precision(modifier , s );
  if(!(nbr == 0 && modifier->precision == 0))
    ft_putstr_fd(s, 1);
  if(modifier->minus)
    l_handle_with(modifier, s , nbr);
  return 0;
}
