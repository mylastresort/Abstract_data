CC 				= c++
CFLAGS			= -Werror -Wextra -Wall -std=c++98 -Iinclude -MMD -MP
COVERAGE_FLAGS	= --coverage
TESTER_STD_FLAG	= -DSTD
VALGRIND_FLAGS	= --leak-check=full \
				  --error-exitcode=1 \
				  --log-file=$(VALGRIND_LOG)
COVERAGE_DIR	= coverage
INCLUDE_DIR		= include
TESTER_DIR		= tests/stamim_tester
DEP				= $(SRC:.cpp=.d) $(SRC:.cpp=.std.d)
OBJ 			= $(SRC:.cpp=.o)
OBJ_STD 		= $(SRC:.cpp=.std.o)
SRC 			= $(TESTER_DIR)/main.cpp \
		  		  $(TESTER_DIR)/vector/constructor.cpp
GCDA_FILES		= $(SRC:.cpp=.gcda)
GCNO_FILES		= $(SRC:.cpp=.gcno)
LCOV_FILE		= $(COVERAGE_DIR)/coverage.info
TEST_LOG_FT		= test_ft.txt
TEST_LOG_STD	= test_std.txt
VALGRIND_LOG	= suppressions.supp
NAME			= ft_tester
NAME_STD		= std_tester

.PHONY: all \
		test \
		test-leaks \
		test-coverage \
		std \
		std-test \
		lint \
		clean-cov \
		clean-dep \
		clean-obj \
		clean-log \
		clean \
		fclean \
		re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

test: all std-test
	@./$(NAME) > $(TEST_LOG_FT)
	@echo "Test logs can be found $(TEST_LOG_FT)"
	@diff -c $(TEST_LOG_FT) $(TEST_LOG_STD)
	@echo "Passed All Tests."

test-leaks: CFLAGS+=-g
test-leaks: all
	valgrind $(VALGRIND_FLAGS) ./$(NAME)

test-coverage: CFLAGS+=$(COVERAGE_FLAGS)
test-coverage: all $(GCNO_FILES)
	@./$(NAME)
	@mkdir -p $(COVERAGE_DIR)
	@gcov -r $(SRC) > /dev/null
	@mv *.gcov $(COVERAGE_DIR)
	@lcov --capture --directory . --output-file $(LCOV_FILE) 2>/dev/null
	@genhtml $(LCOV_FILE) --output-directory $(COVERAGE_DIR)/html

%.gcno: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

std: CFLAGS+=$(TESTER_STD_FLAG)
std: $(NAME_STD)

std-test: std
	@./$(NAME_STD) > $(TEST_LOG_STD)
	@echo "Test logs can be found $(TEST_LOG_STD)"

$(NAME_STD): $(OBJ_STD)
	$(CC) $(CFLAGS) $^ -o $@

%.std.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

lint:
	@clang-format -i --verbose \
	$(shell find $(INCLUDE_DIR) $(TESTER_DIR) -name "*.tpp" \
		-o -name "*.hpp" -o -name "*.cpp")

clean-cov:
	@echo "Cleaning Coverage Files."
	@rm -rf $(GCNO_FILES) $(GCDA_FILES) $(LCOV_FILE) $(COVERAGE_DIR)

clean-dep:
	@echo "Cleaning Dependency Files."
	@rm -f $(DEP)

clean-obj:
	@echo "Cleaning Object Files."
	@rm -f $(OBJ) $(OBJ_STD)

clean-log:
	@echo "Cleaning Log Files."
	@rm -f $(VALGRIND_LOG) $(TEST_LOG_STD) $(TEST_LOG_FT)

clean: clean-obj clean-dep clean-log clean-cov

fclean: clean
	@echo "Cleaning Program Files."
	@rm -f $(NAME) $(NAME_STD)

re: fclean all

-include $(DEP)