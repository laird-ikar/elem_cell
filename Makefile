# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 14:42:09 by bguyot            #+#    #+#              #
#    Updated: 2021/12/16 20:45:19 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = elem_cell

SRCS = srcs/*.c

OBJS = $(SRCS:.c=.o)

LIBS = -lft

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRCS)
	mv *.o srcs
	gcc $(FLAG) -L. $(LIBS) -o $(NAME) $(OBJS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
