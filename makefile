# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corosteg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 13:46:33 by corosteg          #+#    #+#              #
#    Updated: 2017/09/30 14:43:14 by corosteg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIB_PATH = ./srcs/libft/
LIB = $(LIB_PATH)/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = ./srcs/ft_ls.c \
	   ./srcs/check_flags.c \
	   ./srcs/itoa_space2.c \
	   ./srcs/sort_list.c \
	   ./srcs/stock_file_info.c \
	   ./srcs/stock_more_info.c \
	   ./srcs/ls_print.c \
	   ./srcs/date_conversion.c \
	   ./srcs/erase_all.c \
	   ./srcs/big_r.c \
	   ./srcs/more_rights.c \
	   ./srcs/main2.c \
	   ./srcs/itoa_space.c

all: $(NAME)

$(NAME): 
		@echo "\033[31m" "Compiling" [ $(NAME) ]
		make -C $(LIB_PATH)
		$(CC) $(FLAGS) $(SRCS) $(LIB) -o $(NAME)
		@echo "\033[32m" "ft_ls has been Created"
cc:
		$(CC) $(SRCS) $(LIB) -o $(NAME)

clean:
		@echo "\033[34m" "Deleting"
		make -C $(LIB_PATH) clean

fclean:
		@echo "\033[34m" "Deleting"
		/bin/rm -f $(NAME)
		make -C $(LIB_PATH) fclean

re: fclean all
