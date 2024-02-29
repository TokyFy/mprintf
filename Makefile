# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franaivo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:07:39 by franaivo          #+#    #+#              #
#    Updated: 2024/02/21 10:07:39 by franaivo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


sources = ft_printf.c flag_parser.c utils.c

cc = gcc
flags = -Wall -Wextra -Werror
name = libftprintf.a
libft_dir = libft
objects = $(sources:.c=.o)
test_file = a.out

all: $(name)

$(name) : $(objects) lib
	@cp $(libft_dir)/libft.a $(name)
	@ar rcs $(name) $(objects)

$(objects) : %.o : %.c
	@$(cc) -c $(flags) $< -o $@ 

lib :
	@$(MAKE) -C $(libft_dir)

test : all
	cc -g main.c $(name)

clean:
	@rm -f $(objects) $(test_file)

fclean: clean
	@rm -rf $(name)

re : fclean all

