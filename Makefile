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
FLAGS := -Wall -Wextra -Werror
source_dirs := .									\
srcs/convert_to										\
srcs/is_ascii										\
srcs/lst											\
srcs/mem											\
srcs/put											\
srcs/str											\
srcs/get_next_line									\
srcs/ft_printf/										\
srcs/ft_printf/auxiliary							\
srcs/ft_printf/form									\
srcs/ft_printf/parsing								\
srcs/ft_printf/form/form_num						\
srcs/ft_printf/form/form_num/get_num				\
srcs/ft_printf/form/form_str_char					\
srcs/ft_printf/form/form_str_char/form_unicode		\

OBJ_DIR := objs
HEADER := includes/libft.h
MAKE := make
RM := rm -rf

search_wildcards := $(addsuffix /*.c, $(source_dirs))

OBJ = $(notdir $(patsubst %.c, %.o, $(wildcard $(search_wildcards))))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)

VPATH := $(source_dirs)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $(addprefix -I, $(source_dirs)) $<

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) libft.a

re: fclean all

.PHONY: clean fclean re all
