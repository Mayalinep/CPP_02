#color
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

#Name
NAME = Fixed

#Compiler
CXX = c++

#Headers
HEADERS = Fixed.hpp

#Flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#Sources
SRCS = Fixed.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)


#Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re