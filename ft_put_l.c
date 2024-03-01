#include "ft_printf.h"

int ft_put_l(t_modifier *modifier , long long nbr)
{
  __INIT__(char*, s, ft_ltoa(ABS(nbr)));
  __INIT__(int, l_s, ft_strlen(s));
  __INIT__(char, padd_c, ' ');
  __INIT__(char, sign, '\0');
  IF(!s , return -1);
  IF((modifier->precision == 0 && nbr == 0) , return 0);
  IF(modifier->precision != -1 , modifier->zero = 0);
  modifier->precision = max(modifier->precision , l_s);
  IF(modifier->plus || modifier->space, modifier->with--);
  modifier->with = max(modifier->with , modifier->precision);
  IF(modifier->zero && !modifier->minus , padd_c = '0');
  if(nbr > 0)
  {
    IF(modifier->space , sign = ' ');
    IF(modifier->plus , sign = '+');
  }
  ELSE_IF(nbr < 0, sign = '-');
  IF(modifier->zero , repeat(sign, 1));
  IF(!modifier->minus , repeat(padd_c, modifier->with - modifier->precision));
  IF(!modifier->zero , repeat(sign, 1));
  repeat('0', modifier->precision - l_s);
  ft_putstr_fd(s , 1);
  free(s);
  IF(modifier->minus , repeat(padd_c, modifier->with - modifier->precision));
  return modifier->with;
}
