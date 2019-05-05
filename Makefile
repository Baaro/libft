# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 19:42:17 by vsokolog          #+#    #+#              #
#    Updated: 2017/12/16 17:32:41 by vsokolog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC := gcc
FLAGS := -Wall -Wextra -Werror -g

INCLUDES := includes/

source_dirs := .									\
srcs/ascii											\
srcs/get_next_line									\
srcs/list											\
srcs/memory											\
srcs/put											\
srcs/string											\
srcs/system											\
srcs/math/accessors									\
srcs/math/errors									\
srcs/math/memory									\
srcs/math/operations								\
srcs/ft_printf										\
srcs/ft_printf/auxiliary							\
srcs/ft_printf/form									\
srcs/ft_printf/parsing								\
srcs/ft_printf/form/form_num						\
srcs/ft_printf/form/form_num/get_num				\
srcs/ft_printf/form/form_str_char					\
srcs/ft_printf/form/form_str_char/form_unicode		\

MAKE := make
RM := rm -rf

search_wildcards := $(addsuffix /*.c, $(source_dirs))

OBJ = $(notdir $(patsubst %.c, %.o, $(wildcard $(search_wildcards))))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	@echo "\033[092mLibft has compiled successfully!\033[0m"

VPATH := $(source_dirs)

%.o: %.c $(INCLUDES)
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@ -lm

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
