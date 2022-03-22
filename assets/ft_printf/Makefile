# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 13:37:27 by wismith           #+#    #+#              #
#    Updated: 2022/02/12 20:52:46 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST = ft_printf.c ft_put_u.c ft_put.c ft_puthex.c ft_putptr.c ft_int_min.c

HEADER = ft_printf.h

OBJ = $(LIST:.c=.o)

OPTION = -c -I $(HEADER)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@gcc -c $(FLAGS) $(OPTION) $(LIST)
	@ar -rc $(NAME) $(OBJ)

%.o : %.c
	@gcc $(FLAGS) -c $< -o $(<:%.c=%.o)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re