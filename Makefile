# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 19:42:17 by vsokolog          #+#    #+#              #
#    Updated: 2021/03/25 18:31:49 by vsokh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC := gcc
FLAGS := -Wall -Wextra -Werror -g

INCLUDES := inc
source_dirs := .									\
src/convert_to/									\
src/is_ascii										\
src/lst											\
src/mem											\
src/put											\
src/str											\
src/is_dir_file									\
src/convert_to										\
src/swap_bytes										\
src/get_next_line									\
src/ft_printf										\
src/ft_printf/auxiliary							\
src/ft_printf/form									\
src/ft_printf/parsing								\
src/ft_printf/form/form_num						\
src/ft_printf/form/form_num/get_num				\
src/ft_printf/form/form_str_char					\
src/ft_printf/form/form_str_char/form_unicode		\

MAKE := make
RM := rm -rf

RED = '\033[0;31m'
YELLOW = "\033[33m"
GREEN = '\033[0;32m'
NOCOLOR = '\033[0m'

search_wildcards := $(addsuffix /*.c, $(source_dirs))

OBJ = $(notdir $(patsubst %.c, %.o, $(wildcard $(search_wildcards))))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@
	@echo ${GREEN}Libft has successfully compiled!${NOCOLOR}

VPATH := $(source_dirs)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

norm:
	@echo ${YELLOW}[Norminetting $(NAME)]${NOCOLOR}
	~/.norminette/norminette.rb src/* inc/*

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
