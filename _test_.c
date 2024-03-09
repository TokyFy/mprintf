#include "ft_printf.h"
#include <stdio.h>

# define _F "%#.3x"
# define _A 0

int	main(void)
{
  int ft = ft_printf(_F , _A);
  printf("|\n");
  int pr = printf(_F , _A);
  printf("|\n");

  printf("\n%d | %d" , ft , pr);
}
