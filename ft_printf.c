#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

int print_with_format(t_modifier *modifier , char specifier , va_list *args)
{
  if(specifier == 'd' || specifier == 'i')
    return ft_put_l(modifier, va_arg(*args , int));
  else if(specifier == 's')
    return ft_put_s(modifier, va_arg(*args, char *));
  else if(specifier == 'u')
    return ft_put_u(modifier, va_arg(*args, unsigned int));
  else if(specifier == 'x')
    return ft_put_x_lower(modifier, va_arg(*args, unsigned int));
  else if(specifier == 'X')
    return ft_put_x_upper(modifier, va_arg(*args, unsigned int));
  else if(specifier == 'p')
    return ft_put_p(modifier, va_arg(*args, void*));
  else if(specifier == 'c')
    return ft_put_c(modifier, va_arg(*args, int));
  else
  {
    ft_memset(modifier, 0, sizeof(t_modifier));
    return ft_put_c(modifier, specifier);
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
      parse_flags(&format, &modifier , &args);
      int r = print_with_format(&modifier, *format++, &args); 
      if(r != -1)
        count += r;
      else
       return -1;
    }
    if(*format && *format != '%')
    {
      count++;
      ft_putchar_fd(*format, 1);
      format++;
    }
  }
  va_end(args);
  return count;
}

