
NAME = libftprintf.a

CC = cc
CFLAGS = #-Wall -Wextra -Werror

SRCS = 
OBJS = $(SRCS:.c=.o)
HEAD = ftprintf.h




all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft/
	ar cr $@ $^ ./libft/*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD)

clean :
	make -C ./libft/ clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	make -C ./libft/ fclean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all bonus
