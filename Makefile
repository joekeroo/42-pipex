NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

MAIN = main.c
SRC = pipex.c pipex_utils_a.c pipex_utils_b.c pipex_utils_c.c \
	  get_path.c re_path.c run_exec.c here_doc.c run_pipex.c \
	  run_heredoc.c get_next_line.c pipex_utils_d.c
OBJ = ${SRC:.c=.o}

PRINTF_PATH = libftprintf/
PRINTF = libftprintf/libftprintf.a

all: ${NAME}

${NAME}: ${OBJ} ${PRINTF}
	${CC} ${CFLAGS} -o ${NAME} ${MAIN} ${OBJ} ${PRINTF}

${PRINTF}:
	make re -C ${PRINTF_PATH}

clean:
	${RM} ${OBJ}
	make clean -C ${PRINTF_PATH}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${PRINTF_PATH}

re: fclean all

.PHONY = all clean fclean re
