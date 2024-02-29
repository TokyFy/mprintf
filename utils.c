#include "libft/libft.h"

void repeat(char c , int n)
{
  while (n-- > 0) {
    ft_putchar_fd(c, 1);
  }
}

int max(int a , int b)
{
  if(a > b)
    return a;
  return b;
}
