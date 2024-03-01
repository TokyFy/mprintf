#include "ft_printf.h"

int ft_put_base(t_modifier *modifier , unsigned long nbr , char *base , char *sign)
{
  __INIT__(char*, s, ft_ltoa_base((unsigned long)nbr , base));
  __INIT__(int, l_s, ft_strlen(s));
  __INIT__(int, l_sign, ft_strlen(sign));
  __INIT__(char, padd_c, ' ');
  IF(!s , return -1);
  if(modifier->precision == 0  && nbr == 0)
  {
    repeat(' ', modifier->with);
    return modifier->with;
  }
  modifier->precision = max(modifier->precision , l_s);
  IF(nbr == 0 , modifier->hash = 0);
  IF(modifier->hash, modifier->with -= l_sign);
  modifier->with = max(modifier->with , modifier->precision);
  IF(modifier->zero && !modifier->minus , padd_c = '0');
  IF(modifier->hash && modifier->zero, ft_putstr_fd(sign, 1));
  IF(!modifier->minus , repeat(padd_c, modifier->with - modifier->precision));
  IF(modifier->hash && !modifier->zero, ft_putstr_fd(sign, 1));
  repeat('0', modifier->precision - l_s);
  ft_putstr_fd(s , 1);
  free(s);
  IF(modifier->minus , repeat(padd_c, modifier->with - modifier->precision));
  return modifier->with + l_sign;
}
