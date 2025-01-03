# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 13:42:06 by agiliber          #+#    #+#              #
#    Updated: 2024/12/03 11:29:14 by agiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wextra -Werror -std=c++98
RM = rm -rf
EXEC = Brain

RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
MAGENTA= \033[35m
CYAN   = \033[36m
RESET  = \033[0m

SRC = main.cpp
OBJ = ${SRC:%.cpp=%.o}

.SILENCE : $(CC) $(FLAGS) $(SRC) $(EXEC) $(OBJ)

all : Brain

Brain :
	@echo "${CYAN}Compiling Brain...${RESET}"
	@$(CC) $(FLAGS) $(SRC) -o $(EXEC)
	@echo "${GREEN}Succes!!!${RESET}"

clean :
	@echo "${CYAN}Cleaning Brain...${RESET}"
	@$(RM) $(OBJ)
	@echo "${GREEN}Succes!!!${RESET}"

fclean :
	@echo "${CYAN}Cleaning Brain...${RESET}"
	@$(RM) $(OBJ)
	@$(RM) $(EXEC)
	@echo "${GREEN}Succes!!!${RESET}"

re : fclean all

.PHONY : all clean fclean re
