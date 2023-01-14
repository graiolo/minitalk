# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graiolo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 22:07:10 by graiolo           #+#    #+#              #
#    Updated: 2023/01/14 22:07:35 by graiolo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = new_libft

all: $(NAME)

$(NAME): dir
	make -sC libft
	make -sC ft_printf
	make -sC get_next_line

clean:
	make -sC libft clean
	make -sC ft_printf clean
	make -sC get_next_line clean

fclean: clean
	make -sC libft fclean
	make -sC ft_printf fclean
	make -sC get_next_line fclean
	rm -df archive

bonus: dir
	make -sC libft bonus
	make -sC ft_printf bonus
	make -sC get_next_line bonus

norm:	
	norminette | sed -E 's/.*\/(.*)/\1/'

dir:
	if [ ! -d "archive" ]; then \
		mkdir archive; \
	fi

re : fclean all

.PHONY: all clean fclean dir
.SILENT:


