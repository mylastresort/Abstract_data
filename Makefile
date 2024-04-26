NAME = ft_containers
OBJ = $(SRC:.cpp=.o)
SRC = tests/main.cpp
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all