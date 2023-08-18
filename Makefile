CFLAG = -Wall -Wextra -Werror
NAME = so_long
SRC = so_long.c get_next_line.c get_next_line_utils.c so_long_utils.c so_long_utils2.c so_long_utils3.c so_long_utils4.c so_long_utils5.c so_long_utils6.c
MLX = -lmlx 
ARG = -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)
CC = gcc

%.o : %.c
		${CC} $^ -c -o $@

all: ${NAME}

${NAME}:    ${OBJ}
			${CC} ${CFLAG} ${OBJ} ${MLX} ${ARG} -o ${NAME}

clean:
		@rm -rf ${OBJ}

fclean:    clean
			@rm -rf ${NAME} 

re:        fclean all