# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 17:36:16 by tale-fau          #+#    #+#              #
#    Updated: 2021/08/23 18:30:30 by tale-fau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	clang

CFLAGS	=	-Wall -Wextra -Werror

INCLUDES	=	./libft/libft.h \
					./includes/minitalk.h \

LIBFT		=	./libft/libft.a

LIB_DIR		=	./libft

# ------------------------ CLIENT RESOURCES ------------------------------------

CLIENT_NAME	=	client

CLIENT_SRCS	=	./clients/client.c \
					./clients/send_message.c

CLIENT_OBJS	=	${CLIENT_SRCS:.c=.o}

# ------------------------ SERVER RESOURCES ------------------------------------

SERVER_NAME	=	server

SERVER_SRCS	=	./servers/server.c \
					./servers/signal_handler.c

SERVER_OBJS	=	${SERVER_SRCS:.c=.o}

# ------------------------ JOINED RESOURCES ------------------------------------

JOINED_SRCS	=	./joined_resources/pid_check.c \
					./joined_resources/ft_errors.c \

JOINED_OBJS	=	${JOINED_SRCS:.c=.o}

# ------------------------ BONUS -----------------------------------------------

NAME_CLIENT_BONUS	=	client_bonus

NAME_SERVER_BONUS	=	server_bonus

CLIENT_SRCS_BONUS	=	./bonus/clients/client_bonus.c \
							./bonus/clients/send_message_bonus.c

SERVER_SRCS_BONUS	=	./bonus/servers/message_bonus.c \
							./bonus/servers/server_bonus.c \
							./bonus/servers/signal_handler_bonus.c

JOINED_SRCS_BONUS	=	./bonus/joined_resources/ft_errors_bonus.c \
							./bonus/joined_resources/pid_check_bonus.c

CLIENT_OBJS_BONUS	=	${CLIENT_SRCS_BONUS:.c=.o}

SERVER_OBJS_BONUS	=	${SERVER_SRCS_BONUS:.c=.o}

JOINED_OBJS_BONUS	=	${JOINED_SRCS_BONUS:.c=.o}

# ------------------------------------------------------------------------------

all:	${CLIENT_NAME} ${SERVER_NAME}

$(%.o): $(%.c)
		@$(CC) -o $@ -c $^

${CLIENT_NAME}:	${CLIENT_OBJS} ${JOINED_OBJS}
					@make -C ${LIB_DIR}
					@make -C ${LIB_DIR} bonus
					@${CC} -o $@ ${CLIENT_OBJS} ${LIBFT} ${JOINED_OBJS} -I./includes

${SERVER_NAME}:	${SERVER_OBJS}
					@${CC} -o $@ ${SERVER_OBJS} ${LIBFT} ${JOINED_OBJS} -I./includes

bonus:	${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS}

$(NAME_CLIENT_BONUS): ${CLIENT_OBJS_BONUS} ${JOINED_OBJS_BONUS}
						@make -C ${LIB_DIR}
						@make -C ${LIB_DIR} bonus
						@$(CC) -o $@ ${CLIENT_OBJS_BONUS} ${LIBFT} ${JOINED_OBJS_BONUS}  -I./includes

$(NAME_SERVER_BONUS): ${SERVER_OBJS_BONUS}
						@$(CC) -o $@ ${SERVER_OBJS_BONUS} ${LIBFT} ${JOINED_OBJS_BONUS} -I./includes

clean:
					@rm -f servers/*.o
					@rm -f clients/*.o
					@rm -f joined_resources/*.o
					@rm -f bonus/*/*.o
					@make -C libft/ clean
					@echo "\n files deleted\n"

fclean:			clean
					@make -C ${LIB_DIR} fclean
					@${RM} -f ${CLIENT_NAME} ${SERVER_NAME} ${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS}
					@${RM} 
					@echo "\n files deleted \n"

re:				fclean all

.PHONY:			all clean fclean re