#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ABS(Value) (Value < 1) ? -Value : Value
# define IF(boolish , expr) if(boolish) expr
# define ELSE_IF(boolish , expr) else if(boolish) expr
# define __INIT__(type ,var , value) type var = value
# define _FORMAT_(handler,type) handler(modifier , (type)va_arg(args , type))

#include "libft/libft.h"
#include "stdlib.h"

typedef struct modifier
{
  int minus;
  int plus;
  int hash;
  int space;
  int zero;
  int with;
  int precision;
} t_modifier;

int ft_printf(const char *format, ...);
int ft_put_l(t_modifier *modifier , long nbr);
int ft_put_u(t_modifier *modifier , long nbr);
int ft_put_s(t_modifier *modifier , char *str);
int ft_put_c(t_modifier *modifier , char chr);
int ft_put_x(t_modifier *modifier , long nbr);
int ft_put_X(t_modifier *modifier , long nbr);
int ft_put_p(t_modifier *modifier , unsigned long nbr);
int ft_put_base(t_modifier *modifier , unsigned long nbr , char *base , char *sign);

int is_flags(char c);
void parse_flags(const char **format , t_modifier *modifier);
char *ft_ltoa(long long i);
char	*ft_ltoa_base(long i , char* base);

// utils
void repeat(char c , int n);
int max(int a , int b);
int min(int a , int b);

#endif
