#include "ft_printf.h"
#include <stdio.h>

# define _F "|%5p|"
# define _A (void*)1

int	main(void)
{
  int ft = ft_printf(_F , _A);
  printf("\n");
  int pr = printf(_F , _A);

  printf("\n%d | %d" , ft , pr);
}
