# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabril <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/13 21:36:42 by pabril            #+#    #+#              #
#    Updated: 2016/03/17 13:00:59 by pabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

PRINTF_SRC = ft_printf.c \
			 ft_print.c \
			 ft_print2.c \
			 check_arguments.c \
			 ft_flags_ops.c \
			 ft_string_case.c \
			 ft_ptr_case.c \
			 ft_percent_case.c \
			 ft_wide_chars.c \
			 ft_number_case.c \
			 ft_noflag_signed_nb.c \
			 ft_handle_numbers.c \
			 ft_handle_unsigned.c \
			 ft_printxo.c \
			 ft_strlen_wide.c \
			 ft_len_numbers.c \
			 ft_atoi.c \
			 ft_isdigit.c \
			 ft_isspace.c \
			 ft_strlen.c \
			 ft_power.c \
			 ft_strnew.c \
			 ft_memset.c \
			 ft_putcharn.c \
			 ft_putchar_fd.c \
			 ft_strncpy.c

OBJ = $(PRINTF_SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@ echo "building libftprint.a"
	@ $(CC) $(FLAGS) -c $(PRINTF_SRC)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)



clean :
	@ echo "delete *.o"
	@ rm -rf *.o

fclean : clean
	@ echo "delete $(NAME)"
	@ rm -rf $(NAME)

re : fclean all
