#include "ft_printf.h"
#include <stdio.h>

# define _F "|%#050x|\n"
# define _A 65421314

int	main(void)
{
  int ft = ft_printf(_F , _A);
  int pr = printf(_F , _A);

  printf("\n%d | %d" , ft , pr);
}
