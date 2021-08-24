# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 19:01:04 by tale-fau          #+#    #+#              #
#    Updated: 2021/08/24 16:48:51 by tale-fau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
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
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c 

OBJS		=	$(SRCS:.c=.o)

LIB_PATH	=	-L. -lft

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

$(NAME):	${OBJS}
			@ar rc ${NAME} ${OBJS}

all:		${NAME}

.c.o:		${SRCS}
			@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}
	
re: 		fclean all

so:
			$(CC) -fPIC $(FLAGS) $(SRCS)
		gcc -shared -o libft.so $(OBJS)

.PHONY:		all clean fclean re
