NAME = ft_tester
NAME_STD = std_tester
OBJ = $(SRC:.cpp=.o)
OBJ_STD = $(SRC:.cpp=.std.o)
SRC = 	tests/stamim_tester/main.cpp \
		tests/stamim_tester/vector/constructor.cpp
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -Iinclude -MMD -MP
VALGRIND_LOG = suppressions.supp
TEST_LOG_STD = test_std.txt
TEST_LOG_FT = test_ft.txt
DEP = $(SRC:.cpp=.d) $(SRC:.cpp=.std.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

test: all std-test
	@./$(NAME) > $(TEST_LOG_FT)
	@echo "Test logs can be found $(TEST_LOG_FT)"
	diff -c $(TEST_LOG_FT) $(TEST_LOG_STD)
	@echo "Passed All Tests."

test-leaks: CFLAGS+=-g
test-leaks: all
	valgrind \
	--leak-check=full \
	--error-exitcode=1 \
	--log-file=suppressions.supp \
	./$(NAME)

std: CFLAGS+=-DSTD

std: $(NAME_STD)

std-test: std
	@./$(NAME_STD) > $(TEST_LOG_STD)
	@echo "Test logs can be found $(TEST_LOG_STD)"

$(NAME_STD): $(OBJ_STD)
	$(CC) $(CFLAGS) $^ -o $@

%.std.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean-dep:
	@echo "Cleaning Dependency Files."
	@rm -f $(DEP)

clean-obj:
	@echo "Cleaning Object Files."
	@rm -f $(OBJ) $(OBJ_STD)

clean-log:
	@echo "Cleaning Log Files."
	@rm -f $(VALGRIND_LOG) $(TEST_LOG_STD) $(TEST_LOG_FT)

clean: clean-obj clean-dep clean-log

fclean: clean
	@echo "Cleaning Program Files."
	@rm -f $(NAME) $(NAME_STD)

re: fclean all

-include $(DEP)