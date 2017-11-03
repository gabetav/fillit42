# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtavares <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 12:06:04 by gtavares          #+#    #+#              #
#    Updated: 2017/11/01 12:06:06 by gtavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = check_errors.c main.c reader.c map.c count.c get_coord.c decouper.c \
recursive.c
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
MAKE = -C includes/

all: $(NAME)

$(NAME) :
	gcc $(FLAGS) -c $(SRC)
	make $(MAKE) all
	gcc $(FLAGS) $(OBJ) includes/libft.a -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	make $(MAKE) clean
	/bin/rm -f $(OBJ) 

fclean: clean
	/bin/rm -f $(NAME)
	make $(MAKE) fclean

re: fclean all
