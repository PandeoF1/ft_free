# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 13:15:12 by tnard             #+#    #+#              #
#    Updated: 2022/04/08 22:14:31 by tnard            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRCS    =	src/ft_free.c src/ft_free_add.c src/ft_free_remove.c src/ft_free_init.c \
			src/ft_free_size.c src/ft_free_malloc.c
NAME	= ft_free.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c includes/ft_free.h
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${BLU}[BUILD - $(NAME)]${RST} '$<' $(END)"

$(NAME): file $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED) >/dev/null 2>&1 &
	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)"

all: $(NAME)

file:
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/src

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re file