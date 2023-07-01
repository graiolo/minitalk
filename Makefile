# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graiolo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 15:51:02 by graiolo           #+#    #+#              #
#    Updated: 2023/07/01 22:58:39 by graiolo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_NAME	=	server

C_NAME	=	client

S_NAME_B	=	server_bonus

C_NAME_B	=	client_bonus

CC		=	cc

CFLAG	= 	-Wall -Werror -Wextra

RM		=	rm -rf

DLIB	=	libft/

LIB		=	libft/archive/libft.a

ODIR	=	obj/

DIR		=	src/

C_SRC	=	ft_client.c

S_SRC	=	ft_server.c

C_SRC_B	=	ft_client_bonus.c

S_SRC_B	=	ft_server_bonus.c

C_OBJ	= 	$(C_SRC:.c=.o)

S_OBJ	= 	$(S_SRC:.c=.o)

C_OBJ_B	= 	$(C_SRC_B:.c=.o)

S_OBJ_B	= 	$(S_SRC_B:.c=.o)

SRC_C	=	$(addprefix $(DIR), $(C_SRC))

SRC_S	=	$(addprefix $(DIR), $(C_SRC))

SRC_C_B	=	$(addprefix $(DIR), $(C_SRC_B))

SRC_S_B	=	$(addprefix $(DIR), $(C_SRC_B))

OBJ_S	=	$(addprefix $(ODIR), $(S_OBJ))

OBJ_C	=	$(addprefix $(ODIR), $(C_OBJ))

OBJ_S_B	=	$(addprefix $(ODIR), $(S_OBJ_B))

OBJ_C_B	=	$(addprefix $(ODIR), $(C_OBJ_B))

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
RED = \033[0;91m
CIANO = \033[0;96m
YELLOW = \033[0;33m

$(ODIR)%.o : $(DIR)%.c
	@printf "$(YELLOW)Compiling: %s\n$(DEF_COLOR)"  $$(basename "$@" .o)
	@$(CC) $(CFLAG) -c $< -o $@

all: $(C_NAME) $(S_NAME)

$(C_NAME):$(OBJ_C)
	@make -sC $(DLIB)
	@$(CC) $(CFLAG) $(OBJ_C) -o $(C_NAME) $(LIB)
	@echo "$(GREEN)Client compilato correttamente!$(DEF_COLOR)"

$(S_NAME):$(OBJ_S)
	@make -sC $(DLIB)
	@$(CC) $(CFLAG) $(OBJ_S) -o $(S_NAME) $(LIB)
	@echo "$(GREEN)Server compilato correttamente!$(DEF_COLOR)"

$(C_NAME_B):$(OBJ_C_B)
	@make -sC $(DLIB)
	@$(CC) $(CFLAG) $(OBJ_C_B) -o $(C_NAME_B) $(LIB)
	@echo "$(GREEN)Client bonus compilato correttamente!$(DEF_COLOR)"

$(S_NAME_B):$(OBJ_S_B)
	@make -sC $(DLIB)
	@$(CC) $(CFLAG) $(OBJ_S_B) -o $(S_NAME_B) $(LIB)
	@echo "$(GREEN)Server bonus compilato correttamente!$(DEF_COLOR)"

clean:
	@make -sC $(DLIB) clean
	@$(RM) $(OBJ_S) $(OBJ_C) $(OBJ_S_B) $(OBJ_C_B)
	@echo "$(CIANO)file .obj di $(NAME) eliminati con successo!$(DEF_COLOR)"

fclean:
	@$(RM) $(OBJ_S) $(OBJ_C) $(OBJ_S_B) $(OBJ_C_B)
	@echo "$(CIANO)file .obj di $(NAME) eliminati con successo!$(DEF_COLOR)"
	@make -sC $(DLIB)	fclean
	@$(RM) $(C_NAME) $(S_NAME) $(C_NAME_B) $(S_NAME_B)
	@echo "$(RED)client e server eliminati con successo!$(DEF_COLOR)"

re: fclean all

bonus: $(S_NAME_B) $(C_NAME_B)

.PHONY: all clean fclean
