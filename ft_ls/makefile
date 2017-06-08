# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corosteg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 13:46:33 by corosteg          #+#    #+#              #
#    Updated: 2017/06/07 17:46:00 by corosteg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIB_PATH = ./srcs/libft/
LIB = $(LIB_PATH)/libft.a
CC = gcc
FLAGS =
SRCS = ./srcs/ft_ls.c \
	   ./srcs/check_flags.c \
	   ./srcs/sort_list.c \
	   ./srcs/ft_ls_1.c

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
