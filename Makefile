# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 13:12:11 by iwillmot          #+#    #+#              #
#    Updated: 2022/08/29 13:12:13 by iwillmot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# dir
SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./obj

# src
SRC = 	main.c \
		helpers.c \
		threads.c 

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# build
all: obj $(NAME)

obj: 
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all



