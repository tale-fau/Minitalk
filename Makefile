# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 17:36:16 by tale-fau          #+#    #+#              #
#    Updated: 2021/08/21 19:29:38 by tale-fau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	clang

CFLAGS	=	-Wall -Wextra -Werror

INCLUDES	=	./libft/libft.h \
					./includes/minitalk.h \

HEAD		=	./includes/

LIBFT		=	./libft/libft.a

LIB_DIR		=	./libft

OBJS_PATH	=	objs

# ------------------------ CLIENT RESOURCES ------------------------------------

CLIENT_NAME	=	client_c

CLIENT_SRCS	=	./client/client.c \
					./client/send_message.c

CLIENT_OBJS	=	${CLIENT_SRCS:.c=.o}

CLIENT_PATH	=	./client

# ------------------------ SERVER RESOURCES ------------------------------------

SERVER_NAME	=	server_c

SERVER_SRCS	=	./server/server.c \
					./server/signal_handler.c

SERVER_OBJS	=	${SERVER_SRCS:.c=.o}

SERVER_PATH	=	./server

# ------------------------ JOINED RESOURCES ------------------------------------

JOINED_SRCS	=	./joined_resources/pid_check.c \
					./joined_resources/ft_errors.c \
					./joined_resources/ft_putnbr_base.c

JOINED_OBJS	=	${JOINED_SRCS:.c=.o}

JOINED_PATH	=	./joined_resources

# ------------------------------------------------------------------------------

all:	${CLIENT_NAME} ${SERVER_NAME}

${OBJS_PATH}/%.o: ${CLIENT_PATH}/%.c
	@${CC} ${CFLAGS} -o $@ -c $< -I${LIB_PATH}

${OBJS_PATH}/%.o: ${SERVER_PATH}/%.c  
	@${CC} ${CFLAGS} -o $@ -c $< -I${LIB_PATH}

${OBJS_PATH}/%.o: ${JOINED_PATH}/%.c  
	@${CC} ${CFLAGS} -o $@ -c $< -I${LIB_PATH}

${CLIENT_NAME}:	${CLIENT_OBJS} ${JOINED_OBJS}
					@make -C ${LIB_DIR}
					@make -C ${LIB_DIR} bonus
					@${CC} ${CFLAGS} -I${HEAD} -o ${CLIENT_NAME} ${JOINED_OBJS} ${CLIENT_OBJS} ${LIBFT}
					@echo "\n[ CLIENT LOADED ]\n"

${SERVER_NAME}:	${SERVER_OBJS} ${JOINED_OBJS}
					@make -C ${LIB_DIR}
					@make -C ${LIB_DIR} bonus
					@${CC} ${CFLAGS} -I${HEAD} -o ${SERVER_NAME} ${JOINED_OBJS} ${SERVER_OBJS} ${LIBFT}
					@echo "\n[ SERVER LOADED ]\n"

clean:
					@make -C ${LIB_DIR} clean
					@${RM} ${JOINED_OBJS} ${CLIENT_OBJS} ${SERVER_OBJS}
					@echo "\n files deleted\n"

fclean:			clean
					@make -C ${LIB_DIR} fclean
					@${RM} -f ${CLIENT_NAME} ${SERVER_NAME}
					@echo "\n files deleted \n"

re:				fclean all

.PHONY:			all clean fclean re