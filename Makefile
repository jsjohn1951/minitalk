# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 17:26:36 by wismith           #+#    #+#              #
#    Updated: 2022/03/22 18:05:25 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

#Variables
NAME = client server
OBJDIR = OBJECTS
#CLIENT
CLIENT_SRC = client err_check ft_atoi
CINCLUDE = includes/client.h
COBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(CLIENT_SRC)))
#SERVER
SERVER_SRC = server
SINCLUDE = includes/server.h
SOBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SERVER_SRC)))
FLAGS = -Wall -Werror -Wextra
CC = cc
FT_PRINTF = assets/ft_printf

OPTION = -c -I $(CINCLUDE) -c -I $(SINCLUDE)

$(OBJDIR)/%.o : assets/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(OPTION) -c $< -o $@

#commands
all: $(NAME)
	tput setaf 3; echo "--- All Provided ---\n"

client: $(COBJ) $(CINCLUDE)
	make -C $(FT_PRINTF)
	$(CC) $(FLAGS) $(COBJ) $(FT_PRINTF)/libftprintf.a -o client
	tput setaf 2; echo "\nMake Client:"
	tput setaf 3; echo "--- Client Provided ---\n"
	tput setaf 7;

server: $(SOBJ) $(SINCLUDE)
	make -C $(FT_PRINTF)
	$(CC) $(FLAGS) $(SOBJ) $(FT_PRINTF)/libftprintf.a -o server
	tput setaf 2; echo "\nMake Server:"
	tput setaf 3; echo "--- Server Provided ---\n"

$(NAME): $(client) $(server)

clean:
	make clean -C $(FT_PRINTF)
	rm -f -r $(OBJDIR)
	tput setaf 2; echo "\nClean:"
	tput setaf 1; echo "--- Printf Cleaned ---\n--- Objects Cleaned ---\n"

fclean: clean
	make fclean -C $(FT_PRINTF)
	rm -f client
	rm -f server
	tput setaf 2; echo "\nfclean:"
	tput setaf 1; echo "--- Libraries Removed ---\n--- Executables Removed ---\n"
	tput setaf 7;

re: fclean all

.PHONY : all clean fclean re
