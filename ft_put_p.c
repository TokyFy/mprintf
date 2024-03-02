#include "ft_printf.h"

int ft_put_p(t_modifier *modifier , unsigned long nbr)
{
  if(!nbr)
  {
    IF(modifier->precision  != -1 , modifier->precision = 0);
    return ft_put_s(modifier, "(nil)");
  }
  modifier->hash = 1;
  return ft_put_base(modifier, (unsigned long)nbr, "0123456789abcdef", "0x");
}
