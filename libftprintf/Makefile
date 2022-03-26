NAME = libftprintf.a

RM = rm -f
AR = ar rcs

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putvoid.c ft_puthexa.c \
	  ft_putuint.c ft_printf.c
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
