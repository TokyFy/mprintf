#include "ft_printf.h"
#include <stdio.h>

int main()
{
  char *s = "|%d|\n";
  int n = 50;
  ft_printf(s , n);
  printf(s , n);
}
