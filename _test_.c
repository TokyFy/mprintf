#include "ft_printf.h"
#include <stdio.h>

# define _F "|%*p|\n"
# define _V 255

int main()
{
  // printf("%s\n" , ft_ltoa_base(LLONG_MAX, "0123456789abcdef"));
  ft_printf("%c%c%c*", '\0', '1', 1);
  printf("%c%c%c*", '\0', '1', 1);
}
