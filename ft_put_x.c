#include "ft_printf.h"

int ft_put_x(t_modifier *modifier , long nbr)
{
  return ft_put_base(modifier, (unsigned long)nbr, "0123456789abcdef", "0x");
}

int ft_put_X(t_modifier *modifier , long nbr)
{
  return ft_put_base(modifier, (unsigned long)nbr, "0123456789ABCDEF", "0X");
}
