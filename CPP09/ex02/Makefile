# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 13:42:06 by agiliber          #+#    #+#              #
#    Updated: 2025/04/16 14:25:33 by agiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -I./includes/
RM = rm -rf
EXEC = PmergeMe

RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
MAGENTA= \033[35m
CYAN   = \033[36m
RESET  = \033[0m

SRC_DIR = srcs/
OBJ_DIR = obj/
DEP_DIR = dep/

SRC = main.cpp PmergeMe.cpp
OBJ = ${SRC:%.cpp=%.o}
DEP = ${OBJ:%.o=%.d}

SRCF = $(addprefix $(SRC_DIR), $(SRC))
OBJF = $(addprefix $(OBJ_DIR), $(OBJ))
DEPF = $(addprefix $(DEP_DIR), $(DEP))

.SILENCE : $(CC) $(FLAGS) $(SRC) $(EXEC) $(OBJ) $(OBJF) $(OBJ_DIR) \
	$(DEP_DIR) $(SRC_DIR)

all : PmergeMe

PmergeMe : $(OBJF)
	@echo "${CYAN}Compiling PmergeMe...${RESET}"
	@$(CC) $(FLAGS) $(SRCF) -o $(EXEC)
	@echo "${GREEN}Succes!!!${RESET}"

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -MF $(DEP_DIR)$*.d

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(DEP_DIR) :
	@mkdir -p $(DEP_DIR)

clean :
	@echo "${CYAN}Cleaning PmergeMe...${RESET}"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(DEP_DIR)
	@echo "${GREEN}Succes!!!${RESET}"

fclean :
	@echo "${CYAN}Cleaning PmergeMe...${RESET}"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(DEP_DIR)
	@$(RM) $(EXEC)
	@echo "${GREEN}Succes!!!${RESET}"

re : fclean all

.PHONY : all clean fclean re

-include $(DEP)