CFLAG = -Wall -Wextra -Werror -g -fsanitize=address -ofast
NAME = so_long
SRC = so_long.c get_next_line.c get_next_line_utils.c so_long_utils.c so_long_utils2.c
MLX = /home/ta9ra9/minilibx-linux/
ARG = -lmlx -lXext -lX11
OBJ = $(SRC:.c=.o)
CC = gcc

%.o : %.c
		${CC} $^ -c -o $@

all: ${NAME}

${NAME}:    ${OBJ}
			${CC} ${CFLAG} ${OBJ} -L${MLX} ${ARG} -o ${NAME}

clean:
		@rm -rf ${OBJ}

fclean:    clean
			@rm -rf ${NAME} 

re:        fclean all