#include "ft_printf.h"

int ft_put_x_lower(t_modifier *modifier , long nbr)
{
  return ft_put_base(modifier, (unsigned long)nbr, "0123456789abcdef", "0x");
}

int ft_put_x_upper(t_modifier *modifier , long nbr)
{
  return ft_put_base(modifier, (unsigned long)nbr, "0123456789ABCDEF", "0X");
}
