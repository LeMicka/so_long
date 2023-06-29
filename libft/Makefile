# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 12:35:49 by mbruzzi           #+#    #+#              #
#    Updated: 2023/06/29 11:20:08 by mbruzzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc  # C compiler
FLAGS = -Wall -Wextra -Werror  # C flags

AR = ar
ARFLAGS = csr

INCLUDES = libft.h

RM = rm -f   # rm command
 # target lib

SRC =  ft_atoi.c \
		ft_bzero.c	\
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c\
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strcat.c \
		ft_strcpy.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_strcmp.c \
		ft_atoi_long.c \
		ft_printf.c \
		ft_printhex.c \
		ft_printnbr.c \
		ft_printptr.c \
		printf_functions.c \
		get_next_line.c \
		get_next_line_bonus.c \
		ft_free_tab.c \

BONUS_SRC = 	ft_lstnew.c \
	  		ft_lstadd_front.c \
	  		ft_lstsize.c \
	  		ft_lstlast.c \
	  		ft_lstadd_back.c \
	  		ft_lstdelone.c \
	  		ft_lstclear.c \
	  		ft_lstiter.c \
	  		ft_lstmap.c	\

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(AR) $(ARFLAGS) $@ $^

$(OBJS) : $(SRC) $(INCLUDES)
		$(CC) $(FLAGS) -c $(SRC)

$(BONUS_OBJS) : $(BONUS_SRC) $(INCLUDES)
		$(CC) $(FLAGS) -c $(BONUS_SRC)

bonus : $(OBJS) $(BONUS_OBJS)
		$(AR) $(ARFLAGS) $(NAME) $^

clean :
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	 	$(RM) $(NAME) $(OBJS) $(BONUS_OBJS)

re : fclean all
	
.PHONY: all bonus clean fclean re
