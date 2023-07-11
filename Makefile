UNAME := $(shell uname)
NAME        := so_long
CC        := gcc
FLAGS    := -g -Wall -Werror -Wextra

RM  = rm -f

LIBFT = libft/libft.a

LIBMLX	:= ./mlx/
# MLX = -L ./mlx/build/CMakeFiles/ -lmlx42 -framework OpenGL -framework AppKit
MLX = mlx/build/libmlx42.a -framework OpenGL -framework AppKit -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/

#                                 PROGRAM'S SRCS                               #


SRCS        :=	srcs/main.c \
				srcs/map/map_init.c \
				srcs/map/map_errors.c \
				srcs/map/map_struct.c \
				srcs/map/map_resolvable.c \
				srcs/map/map_to_window.c \


OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

ifeq ($(shell uname), Linux)	
MLX = mlx/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lXext -lX11 -lm
endif

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

all:		${NAME}

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME):	$(OBJS)
			@echo " [ .. ] | Compiling $(BLUE)libft$(CLR_RMV).."
			make -C libft
			@echo " $(GREEN)[ OK ] | Libft ready!"
			$(CC) $(OBJS) $(LIBFT) $(MLX) $(CFLAGS) -o $(NAME)

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME} ${LIBFT}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re