#include "ft_printf.h"
#include <stdio.h>

# define _F "|%s %d|\n"
# define _A "hello", 42

int	main(void)
{
  int ft = ft_printf(_F , _A);
  int pr = printf(_F , _A);

  printf("\n%d | %d" , ft , pr);
}
