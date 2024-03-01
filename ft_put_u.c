#include "ft_printf.h"

int ft_put_u(t_modifier *modifier , long nbr)
{
  modifier->plus = 0;
  return ft_put_l(modifier, (unsigned int)nbr);
}
