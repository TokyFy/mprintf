# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franaivo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:07:39 by franaivo          #+#    #+#              #
#    Updated: 2024/03/09 15:57:46 by franaivo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


sources = ft_printf.c flag_parser.c ft_put_c.c \
					ft_put_l.c ft_put_p.c ft_put_s.c ft_put_u.c 	\
					ft_put_x.c ft_put_base.c \
					utils/minmax.c utils/string.c utils/ft_ltoa.c utils/ft_itoa_base.c \
					utils/ft_ultoa_base.c

cc = gcc
flags = -g -Wall -Wextra -Werror
name = libftprintf.a
libft_dir = libft
objects = $(sources:.c=.o)

test_exec = a.out
test_files = $(test_exec)

all: $(name)
bonus: all
$(name) : $(objects) lib
	@cp $(libft_dir)/libft.a $(name)
	@ar rcs $(name) $(objects)

$(objects) : %.o : %.c
	@$(cc) -c $(flags) $< -o $@ 

lib :
	@$(MAKE) -C $(libft_dir)

test : all
	cc -g _test_.c $(name) -o $(test_exec)
	./$(test_exec)
	
clean:
	@$(MAKE) -C $(libft_dir) clean
	@rm -f $(objects) $(test_files)

fclean: clean
	@$(MAKE) -C $(libft_dir) fclean
	@rm -rf $(name)

re : fclean all

