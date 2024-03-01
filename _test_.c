#include "ft_printf.h"
#include <stdio.h>


#define _FMT_ "|%+50.3s|"
#define _ARG_ "1.2"

int main()
{
  int ft_p = 0;
  char p = 'a';

  ft_p =  ft_printf(_FMT_ , _ARG_);
          ft_printf("%d \n" , ft_p);
  p =     printf(_FMT_,_ARG_);
          printf("%d \n" ,p);
}
