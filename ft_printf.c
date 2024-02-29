#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

int _out_int(t_modifier *modifier , int nbr)
{
  // Sorry for this bullshit
  __INIT__(char*, s, ft_itoa(ABS(nbr)));
  __INIT__(int, l_s, ft_strlen(s));
  __INIT__(char, padd_c, ' ');
  __INIT__(char, sign, '\0');
  IF(!s , return -1);
  IF((modifier->precision == 0 && nbr == 0) , return 0);
  modifier->precision = max(modifier->precision , l_s);
  IF(modifier->plus || modifier->space, modifier->with--);
  modifier->with = max(modifier->with , modifier->precision);
  IF(modifier->zero && !modifier->minus , padd_c = '0');
  if(nbr > 0)
  {
    IF(modifier->space , sign = ' ');
    IF(modifier->plus , sign = '+');
  }
  ELSE_IF(nbr < 0, sign = '-');
  IF(modifier->zero , repeat(sign, 1));
  IF(!modifier->minus , repeat(padd_c, modifier->with - modifier->precision));
  IF(!modifier->zero , repeat(sign, 1));
  repeat('0', modifier->precision - l_s);
  ft_putstr_fd(s , 1);
  free(s);
  IF(modifier->minus , repeat(padd_c, modifier->with - modifier->precision));
  return modifier->with;
}

int print_with_format(t_modifier *modifier , char specifier , va_list args)
{
  if(specifier == 'd')
    return _out_int(modifier, va_arg(args, int));

  return 0;
}

int ft_printf(const char *format, ...)
{
  va_list args;
  va_start(args, format);

  while (*format) {
    if(*format == '%')
    {
      format++;
      t_modifier modifier;
      ft_bzero(&modifier, sizeof(t_modifier));
      modifier.precision = -1;
      parse_flags(&format, &modifier);
      print_with_format(&modifier, *format++, args);
    }
    if(*format)
    {
      ft_putchar_fd(*format, 1);
      format++;
    }
  }
  va_end(args);
  return 0;
}

