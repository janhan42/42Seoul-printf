# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 13:40:39 by janhan            #+#    #+#              #
#    Updated: 2023/10/10 12:54:45 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
HEAD = libft.h
SRCS_MAND = ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
		ft_strncmp.c  ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_MAND = $(SRCS_MAND:.c=.o)

all : $(NAME)

$(NAME): $(OBJS_MAND)
	ar cr $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD)

clean :
	rm -f $(OBJS_MAND) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all bonus
