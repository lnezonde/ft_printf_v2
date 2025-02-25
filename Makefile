NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

SRC = ft_printf.c \
	print_di.c \
	print_p.c \
	print_s.c \
	print_c.c \
	print_uxx.c \
	read_data.c \
	return_val.c \
	utils.c \
	utils2.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $< $(CFLAGS)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:

.PHONY: all re clean fclean
