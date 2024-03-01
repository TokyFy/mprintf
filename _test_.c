#include "ft_printf.h"
#include <stdio.h>


#define _FMT_ "|%c|"


int main()
{
  int ft_p = 0;
  char p = 'a';

  ft_p =  ft_printf(_FMT_ , p);
          ft_printf("%d \n" , ft_p);
  p =     printf(_FMT_,p);
          printf("%d \n" ,p);
}
