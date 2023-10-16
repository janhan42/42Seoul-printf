# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 23:50:52 by janhan            #+#    #+#              #
#    Updated: 2023/10/14 00:06:47 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a
HEAD		= ft_printf.h

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRCS		= ft_printf.c \
			ft_print_parse.c \
			ft_print_char.c \
			ft_print_str.c \
			ft_print_num.c \
			ft_print_num_print.c

OBJS      = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I$(HEAD)

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $@ $?

bonus :

clean :
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re bonus
