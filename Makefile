# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 11:41:37 by brheaume          #+#    #+#              #
#    Updated: 2022/11/18 14:36:43 by brheaume         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_utils.c	\
	  ft_conversion.c \
	  ft_printf.c

OBJ = ${SRC:.c=.o}

CC = clang
CFLAGS = -Wall -Werror -Wextra

ARCHIVE = ar -rcs $(NAME) $(OBJ)

LIBERATE = rm -rf

LIBFT  = libft.a
LIBDIR = libft/

all: libft $(NAME)

$(NAME): $(OBJ)
	cp $(LIBDIR)$(LIBFT) $(NAME)
	$(ARCHIVE)
	@echo "\nPrintf Archived\n"

clean:
	$(LIBERATE) $(OBJ)
	$(LIBERATE) $(LIBDIR)*.o

fclean: clean
	$(LIBERATE) $(NAME)
	$(LIBERATE) $(LIBDIR)$(LIBFT)

re: fclean all

libft: 
	$(MAKE) -C $(LIBDIR)

.PHONY: all libft
