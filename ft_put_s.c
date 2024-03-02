#include "ft_printf.h"

int ft_put_s(t_modifier *modifier , char *str)
{
  if(!str)
  {
    IF(modifier->precision < 6 && modifier->precision != -1 , modifier->precision = 0);
    return ft_put_s(modifier, "(null)");
  }
  t_size_t l_str = ft_strlen(str);
  char *s = ft_substr(str, 0, modifier->precision);
  IF(modifier->precision == -1 , modifier->precision = l_str);
  modifier->precision = min(modifier->precision , l_str);
  modifier->with = max(modifier->with, modifier->precision);
  IF(!s , return -1);
  IF(!modifier->minus , repeat(' ', modifier->with - modifier->precision));
  ft_putstr_fd(s, 1);
  free(s);
  IF(modifier->minus , repeat(' ', modifier->with - modifier->precision));
  return modifier->with;
}
