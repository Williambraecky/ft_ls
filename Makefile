# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 11:30:33 by wbraeckm          #+#    #+#              #
#    Updated: 2018/09/21 13:27:59 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
FLAGS = -O3 -Wall -Wextra -Werror
INCLUDES = includes/
LIBFTFOLDER = libft
LIBFTINCLUDES = $(LIBFTFOLDER)/includes/
LIBFT = $(LIBFTFOLDER)/libft.a
SRCSFOLDER = srcs
OBJFOLDER = obj

ITEMS = $(shell find srcs -type f | grep -E "\.c$$" | sed 's/srcs//g')
SRCS = $(addprefix $(SRCSFOLDER), $(ITEMS))
OBJ = $(addprefix $(OBJFOLDER), $(ITEMS:.c=.o))
SRCSUBS = $(shell find ./srcs -type d)
OBJSUBS = $(SRCSUBS:./srcs%=./obj%)

ccred = "\033[0;91m"
ccgreen = "\033[0;92m"
ccmagenta = "\033[0;96m"
ccreset = "\033[0;0m"

all: LIB $(NAME)

$(OBJFOLDER)/%.o:$(SRCSFOLDER)/%.c
	@printf $(ccgreen)
	$(CC) $(FLAGS) -o $@ -c $< -I$(INCLUDES) -I$(LIBFTINCLUDES)
	@printf $(ccreset)

$(OBJSUBS):
	@mkdir $@

LIB:
	@make -C $(LIBFTFOLDER)

$(NAME): $(OBJSUBS) $(OBJ)
	@printf $(ccmagenta)
	gcc -o $(NAME) $(FLAGS) $(LIBFT) $(OBJ)
	@printf $(ccreset)

clean:
	@printf $(ccred)
	/bin/rm -rf obj/
	make -C $(LIBFTFOLDER) clean
	@printf $(ccreset)

fclean: clean
	@printf $(ccred)
	/bin/rm -f $(NAME)
	make -C $(LIBFTFOLDER) fclean
	@printf $(ccreset)

re: fclean all

norm:
	@norminette $(INCLUDES) $(SRCSFOLDER)
	make -C $(LIBFTFOLDER) norm

.PHONY: norm clean fclean re
