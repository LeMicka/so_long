NAME        := so_long
CC        := gcc
FLAGS    := 

RM  = rm -f

LIBFT = libft/libft.a

LIBMLX	:= ./mlx/
# MLX = -L ./mlx/build/CMakeFiles/ -lmlx42 -framework OpenGL -framework AppKit
MLX = mlx/build/libmlx42.a -framework OpenGL -framework AppKit
LIBS = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/

#                                 PROGRAM'S SRCS                               #


SRCS        :=	main.c \

OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

all:		libmlx ${NAME}

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME):	$(OBJS)
			@echo " [ .. ] | Compiling $(BLUE)libft$(CLR_RMV).."
			make -C libft
			@echo " $(GREEN)[ OK ] | Libft ready!"
			$(CC) $(OBJS) $(LIBFT) $(MLX) $(LIBS) $(CFLAGS) -o $(NAME)

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re