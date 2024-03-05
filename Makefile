# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 20:25:59 by cvignar           #+#    #+#              #
#    Updated: 2020/11/28 16:00:39 by cvignar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strlen.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strnstr.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strncmp.c \
		  ft_atoi.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c
OBJ		= $(SRC:.c=.o)

NAME	= libft.a

all:		$(NAME)

$(NAME): $(OBJ) libft.h.gch
			ar rcs $(NAME) $(OBJ) libft.h.gch
			ranlib $(NAME)

.c.o:
			gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

libft.h.gch:
			gcc -Wall -Wextra -Werror -c libft.h -o libft.h.gch

clean:
			rm -fv $(OBJ) libft.h.gch

fclean:		clean
			rm -fv $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
