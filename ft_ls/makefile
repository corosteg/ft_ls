# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corosteg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 13:46:33 by corosteg          #+#    #+#              #
#    Updated: 2017/04/10 15:26:43 by corosteg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIB_PATH = ./libft/
LIB = $(LIB_PATH)/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = main.c

all: $(NAME)

$(NAME): 
		@echo "\033[31m" "Compiling" [ $(NAME) ] 
		make -C ./libft/
		$(CC) $(FLAGS) $(SRCS) $(LIB) -o $(NAME)
		@echo "\033[32m" "ft_ls has been Created"
cc:
		$(CC) $(SRCS) $(LIB) -o $(NAME)

clean:
		@echo "\033[34m" "Deleting"
		make -C ./libft/ clean

fclean:
		@echo "\033[34m" "Deleting"
		/bin/rm -f $(NAME)
		make -C ./libft/ fclean

re: fclean all
