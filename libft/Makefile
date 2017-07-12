#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 16:50:26 by gvandeve          #+#    #+#              #
#    Updated: 2017/02/17 17:08:46 by gvandeve         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libft.a

SRC		=	lib/*.c get_next_line/*.c ft_printf/*.c

COMP	=	*.o

HEADF	=	includes/

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror -g $(SRC) -I includes/
	@ar rc $(NAME) $(COMP)
	@ranlib $(NAME)

clean:
	@rm -f $(COMP)

fclean: clean
	@rm -f $(NAME)

re: fclean all
