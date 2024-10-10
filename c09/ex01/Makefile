# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 14:59:54 by asafrono          #+#    #+#              #
#    Updated: 2024/10/08 13:16:36 by asafrono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
INCDIR = includes
SRCS = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
HEADER = $(INCDIR)/ft.h

all: $(NAME)

$(NAME): $(OBJS)
	echo "Creating library $(NAME)"
	ar rcs $(NAME) $(OBJS)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	echo "Compiling $<"
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	echo "Removing object files"
	rm -f $(OBJS)

fclean: clean
	echo "Removing $(NAME)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
