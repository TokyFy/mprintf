#include "ft_printf.h"
#include <stdarg.h>

int print_with_format(t_modifier *modifier , char specifier , va_list args)
{
  IF     (specifier == 'd' || specifier == 'i', return _FORMAT_(ft_put_l, int));
  ELSE_IF(specifier == 's', return _FORMAT_(ft_put_s, char*));
  ELSE_IF(specifier == 'c', return _FORMAT_(ft_put_c, int));
  ELSE_IF(specifier == 'x', return _FORMAT_(ft_put_x, unsigned int));
  ELSE_IF(specifier == 'X', return _FORMAT_(ft_put_X, unsigned int));
  ELSE_IF(specifier == 'p', return _FORMAT_(ft_put_p, unsigned long));
  else
  {
    ft_memset(modifier , 0,sizeof(t_modifier));
    return ft_put_c(modifier , specifier);
  }
  return -1;
}

int ft_printf(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  t_size_t count = 0;

  while (*format) {
    if(*format == '%')
    {
      format++;
      t_modifier modifier;
      ft_bzero(&modifier, sizeof(t_modifier));
      modifier.precision = -1;
      parse_flags(&format, &modifier);
      count += print_with_format(&modifier, *format++, args);
    }
    if(*format)
    {
      count++;
      ft_putchar_fd(*format, 1);
      format++;
    }
  }
  va_end(args);
  return count;
}

