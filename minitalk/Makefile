# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graiolo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 15:51:02 by graiolo           #+#    #+#              #
#    Updated: 2023/01/13 18:47:20 by graiolo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	minitalk

DLIB	=	libft/

LIB		=	libft/archive/libft.a

S_NAME	=	server

C_NAME	=	client

ODIR	=	obj/

DIR		=	src/

C_SRC	=	ft_client.c \)


S_SRC	=	ft_server.c \

C_OBJ	= 	$(C_SRC:.c=.o)

S_OBJ	= 	$(S_SRC:.c=.o)

RM		=	rm -rf

CC		=	cc

CFLAG	= 	-Wall -Werror -Wextra -g

SRC_C	=	$(addprefix $(DIR), $(C_SRC))

SRC_S	=	$(addprefix $(DIR), $(C_SRC))

OBJ_S	=	$(addprefix $(ODIR), $(S_OBJ))

OBJ_C	=	$(addprefix $(ODIR), $(C_OBJ))

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
RED = \033[0;91m
CIANO = \033[0;96m

$(ODIR)%.o : $(DIR)%.c
	$(CC) $(CFLAG) -c $< -o $@ -I libft/include 

all: $(NAME)

$(NAME): client server

client: dir lib $(OBJ_C)
	$(CC) $(CFLAG) $(OBJ_C) -o $(C_NAME) $(LIB)
	@echo "$(NAME): $(GREEN)Client compilato correttamente!$(DEF_COLOR)"

server:	dir lib $(OBJ_S)
	$(CC) $(CFLAG) $(OBJ_S) -o $(S_NAME) $(LIB)
	@echo "$(NAME): $(GREEN)Server compilato correttamente!$(DEF_COLOR)"

clean:
	@make -C $(DLIB) clean
	$(RM) $(OBJ_S) $(OBJ_C)
	$(RM) $(ODIR)
	@echo "$(NAME): $(CIANO)Obj file eliminati correttamente!$(DEF_COLOR)"


fclean: clean
	@make -C $(DLIB)	fclean
	$(RM) $(C_NAME) $(S_NAME)
	@echo "$(NAME): $(RED)Client e Server eliminati correttamente!$(DEF_COLOR)"

dir:
	if [ ! -d "$(ODIR)" ]; then \
		mkdir $(ODIR); \
	fi

lib:
	if [ ! -f "$(LIB)" ]; then \
		make -C $(DLIB) all; \
	fi

norm:
	norminette

push:
	git add *
	git commit -m "minitalk: make push"
	git push

re: fclean all

bonus: all

.PHONY: all client server clean fclean norm
.SILENT:
