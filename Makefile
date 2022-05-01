# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 16:03:14 by mdiallo           #+#    #+#              #
#    Updated: 2022/03/14 15:06:03 by mdiallo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SHELL=/bin/bash

NAME		= container

AR = ar rcs
CPPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98 -fsanitize=address
OBJ_DIR = obj
RM = rm -f
PP = clang++
PRINTF = LC_NUMERIC="en_US.UTF-8" printf

SRC = 	main.cpp vector_test.cpp iterator_traits_test.cpp random_access_iterator_test.cpp \
		reverse_iterator_test.cpp utility_test.cpp algorithm_test.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

all: $(NAME)

$(NAME): create_dirs $(OBJ)
	@$(PP) $(CPPFLAGS) $(OBJ) -o $@
	@$(PRINTF) "\r%50s\r$(GREEN)$(NAME) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o:%.cpp
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@printf "\r%50s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(PP) $(CPPFLAGS) -c $< -o $@

create_dirs:
	@mkdir -p $(OBJ_DIR)

clean :
	@$(PRINTF) "$(CYAN)Cleaning up object files in $(NAME)...$(DEFAULT)\n"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"
	@$(RM) $(NAME)

re: fclean
	@make all

.PHONY: all clean fclean create_dirs re

