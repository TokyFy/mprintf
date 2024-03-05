#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int is_flags(char c)
{
  return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

void parse_flags(const char **format , t_modifier *modifier , va_list *args)
{
  while (is_flags(**format) && **format) {
    if(**format == '-')
      modifier->minus = 1;
    else if(**format == '+')
      modifier->plus = 1;
    else if(**format == ' ')
      modifier->space = 1;
    else if(**format == '#')
      modifier->hash = 1;
    else if(**format == '0')
      modifier->zero = 1;
    (*format)++;
  }
  while (ft_isdigit(**format) && **format) {
    modifier->with = modifier->with * 10 + (**format - '0');
    (*format)++;
  }
  if(**format ==  '*')
  {
    modifier->with = va_arg(*args, int);
    if(modifier->with < 0)
    {
      modifier->minus = 1;
      modifier->with *= -1;
    }
    (*format)++;
  }
  if(**format == '.')
  {
    (*format)++;
    modifier->precision = 0;
    while (ft_isdigit(**format) &&  **format) {
      modifier->precision = modifier->precision * 10 + (**format - '0');
      (*format)++;
    }
    if(**format ==  '*')
    {
      modifier->precision = va_arg(*args, unsigned int);
      (*format)++;
    }
  }
}

