NAME = Zombie

SRC = Zombie.cpp main.cpp zombieHorde.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Zombie.hpp

FLAGS = -Wall -Werror -Wextra -std=c++98

GREEN 	= \033[32m
YELLOW 	= \033[33m
END 	= \033[0m

%.o:%.cpp $(HEADERS)
	@c++ $(FLAGS) -c $< -o $@

all: $(NAME)
$(NAME):$(OBJ)
	@c++ $(FLAGS) $(OBJ) -o $@
	@echo "$(GREEN)$(NAME) was compiled! 🤠$(END)"

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW)Object file was deleted! 🤠$(END)"
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) was deleted! 🤠$(END)"

re:	fclean all
	@echo "$(GREEN)Project was reloaded! 🤠$(END)"

.PHONY: all clean fclean re