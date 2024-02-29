#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ABS(Value) (Value < 1) ? -Value : Value
# define IF(boolish , expr) if(boolish) expr
# define ELSE_IF(boolish , expr) else if(boolish) expr
# define __INIT__(type ,var , value) type var = value
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

int is_flags(char c);
void parse_flags(const char **format , t_modifier *modifier);

// utils

void repeat(char c , int n);
int max(int a , int b);

#endif
