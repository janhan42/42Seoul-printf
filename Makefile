# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 10:58:10 by janhan            #+#    #+#              #
#    Updated: 2023/10/26 14:33:39 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a
HEAD		= ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS  = ft_printf.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_di.c \
		ft_print_hex.c \
		ft_print_u.c \
		ft_print_address.c
OBJS  = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD)

clean :
	make -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean bonus re
