#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/15 12:06:25 by gvandeve          #+#    #+#              #
#    Updated: 2017/06/10 14:07:34 by gvandeve         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	gen_map
DIRSRC		=	./srcs
INCLUDE		=	./includes
SRC			=	$(DIRSRC)/*.c
OBJ			=	*.o
LIBDIR		=	../libft
LIB			=	$(LIBDIR)/libft.a
CFLAGS		=	-g -Wall -Wextra -Werror
CC			=	gcc

all: $(NAME)

$(NAME): $(SRC)
	make -C $(LIBDIR)
	$(CC) -c $(FLAGS) $(SRC) -I $(INCLUDE)
	$(CC) -g $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	find . \( -name "#*#" -o -name "*~" \) -print -delete
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all
