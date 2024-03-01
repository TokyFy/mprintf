#include "ft_printf.h"

int is_flags(char c)
{
  return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

void parse_flags(const char **format , t_modifier *modifier)
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
  while (ft_isdigit(**format)) {
    modifier->with = modifier->with * 10 + (**format - '0');
    (*format)++;
  }
  if(**format == '.')
  {
    (*format)++;
    modifier->precision = 0;
    while (ft_isdigit(**format)) {
      modifier->precision = modifier->precision * 10 + (**format - '0');
      (*format)++;
    }
  }
}

