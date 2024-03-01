#include "ft_printf.h"

int ft_put_c(t_modifier *modifier , char chr)
{
  char s[2] = " ";
  *s = chr;
  modifier->precision = 1;
  ft_put_s(modifier, s);
  return 1;
}
