NAME = ft_containers
OBJ = $(SRC:.cpp=.o)
SRC = tests/main.cpp
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -Iinclude
VALGRIND_LOG = suppressions.supp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

test: all
	@./$(NAME)

test-leaks: all
	valgrind \
	--leak-check=full \
	--error-exitcode=1 \
	--log-file=suppressions.supp \
	./$(NAME)

clean:
	rm -rf $(OBJ) $(VALGRIND_LOG)

fclean: clean
	rm -rf $(NAME)

re: fclean all