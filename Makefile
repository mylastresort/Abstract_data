MAKEFLAGS += -j10
CC 				= c++
CFLAGS			= -Werror -Wextra -Wall -std=c++98 -Iinclude -MMD -MP -Wfatal-errors $(EXTRA_CFLAGS)
COVERAGE_FLAGS	= --coverage
TESTER_STD_FLAG	= -DSTD
TESTER_BAD_FLAG	= -DBAD
VALGRIND_FLAGS	= --leak-check=full \
				  --error-exitcode=1 \
				  --log-file=$(VALGRIND_LOG)
BUILD_DIR		= target
COVERAGE_DIR	= $(BUILD_DIR)/coverage
INCLUDE_DIR		= include
TESTER_DIR		= tests/stamim_tester
DEP				= $(patsubst %.cpp,$(BUILD_DIR)/%.d,$(SRC)) \
				  $(patsubst %.cpp,$(BUILD_DIR)/%.std.d,$(SRC)) \
				  $(patsubst %.cpp,$(BUILD_DIR)/%.bad.d,$(SRC_BAD))
OBJ 			= $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC))
OBJ_STD 		= $(patsubst %.cpp,$(BUILD_DIR)/%.std.o,$(SRC))
OBJ_BAD 		= $(patsubst %.cpp,$(BUILD_DIR)/%.bad.o,$(SRC_BAD))
SRC 			= $(TESTER_DIR)/main.cpp \
				  $(TESTER_DIR)/vector/constructor.cpp \
				  $(TESTER_DIR)/vector/cplusplus_examples.cpp \
				  $(TESTER_DIR)/deque/cplusplus_examples.cpp \
				  $(TESTER_DIR)/deque/main.cpp \
				  $(TESTER_DIR)/list/cplusplus_examples.cpp
SRC_BAD 		= $(TESTER_DIR)/vector/constructor.cpp
GCDA_FILES		= $(patsubst %.cpp,$(BUILD_DIR)/%.gcda,$(SRC))
GCNO_FILES		= $(patsubst %.cpp,$(BUILD_DIR)/%.gcno,$(SRC))
LCOV_FILE		= $(COVERAGE_DIR)/coverage.info
TEST_LOG_FT		= $(BUILD_DIR)/test_ft.txt
TEST_LOG_STD	= $(BUILD_DIR)/test_std.txt
VALGRIND_LOG	= $(BUILD_DIR)/suppressions.supp
NAME			= $(BUILD_DIR)/ft_tester
NAME_STD		= $(BUILD_DIR)/std_tester
PHC = $(INCLUDE_DIR)/_phc.hpp
PHC_GCH = $(BUILD_DIR)/$(INCLUDE_DIR)/_phc.hpp.gch

.PHONY: all \
		test \
		test-bad \
		test-leaks \
		cov \
		std \
		std-test \
		lint-staged \
		lint \
		clean-cov \
		clean-dep \
		clean-obj \
		clean-log \
		clean \
		fclean \
		re

# all: test
all: build
build: $(NAME)

$(NAME): $(OBJ) | $(BUILD_DIR)
	@echo "\033[1;34m[Linking] $@\033[0m"
	@$(CC) $(CFLAGS) $^ -o $@

$(PHC_GCH): $(PHC) | $(BUILD_DIR)/$(INCLUDE_DIR)
	@echo "\033[1;33m[Building] PHC Header File\033[0m"
	@$(CC) $(CFLAGS) -x c++-header $< -o $@

$(BUILD_DIR)/%.o: %.cpp $(PHC_GCH) | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	@echo "\033[1;33m[Building] $@\033[0m"
	@$(CC) $(CFLAGS) -include $(PHC) -c $< -o $@

test-bad: $(OBJ_BAD)
	@echo "\033[1;32m[Testing] OK. Bad files did not compile as expected.\033[0m"

$(BUILD_DIR)/%.bad.o: %.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	@if $(CC) $(CFLAGS) $(TESTER_BAD_FLAG) -c $< -o $@ 2>/dev/null; \
	then \
		echo "\033[1;31m$< should not compile after defining BAD macro\033[0m" && \
		exit 1; \
	fi

test: test-bad build std-test
	@$(NAME) > $(TEST_LOG_FT)
	@echo "\033[1;32m[Testing] Test logs can be found $(TEST_LOG_FT)\033[0m"
	@diff -c $(TEST_LOG_FT) $(TEST_LOG_STD)
	@echo "\033[1;32m[Testing] Passed All Tests.\033[0m"

test-leaks: CFLAGS+=-g
test-leaks: build
	valgrind $(VALGRIND_FLAGS) $(NAME) > /dev/null

cov: CFLAGS+=$(COVERAGE_FLAGS)
cov: build
	@echo "\033[1;34m[Coverage] Generating coverage report...\033[0m" 	
	@$(NAME)
	@echo "\033[1;32m[Coverage] Coverage report generated.\033[0m"
	@mkdir -p $(COVERAGE_DIR)
	@echo "\033[1;34m[Coverage] Generating .gcov files...\033[0m"
	@gcov -r $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC)) > /dev/null
	@echo "\033[1;32m[Coverage] .gcov files generated.\033[0m"
	@mv *.gcov $(COVERAGE_DIR)
	@echo "\033[1;34m[Coverage] Generating lcov report...\033[0m"
	@lcov --capture --directory . --output-file $(LCOV_FILE) 2>/dev/null
	@lcov --remove $(LCOV_FILE) "/usr/*" --output-file $(COVERAGE_DIR)/filtered.info
	@genhtml $(COVERAGE_DIR)/filtered.info --output-directory $(COVERAGE_DIR)/html --title "Coverage Report"
	@echo "\033[1;32m[Coverage] Include-only coverage report: $(COVERAGE_DIR)/html/index.html\033[0m"

std: CFLAGS+=$(TESTER_STD_FLAG)
std: $(NAME_STD)

std-test: std
	@$(NAME_STD) > $(TEST_LOG_STD)
	@echo "\033[1;32m[Testing] Test logs can be found $(TEST_LOG_STD)\033[0m"

$(NAME_STD): $(OBJ_STD) | $(BUILD_DIR)
	@echo "\033[1;34m[Linking] $@\033[0m"
	@$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.std.o: %.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	@echo "\033[1;33m[Building] $@\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(INCLUDE_DIR):
	@mkdir -p $(BUILD_DIR)/$(INCLUDE_DIR)

lint-staged:
	@git diff --cached --name-only | \
		grep -E '\.(cpp|hpp|tpp)$$' | \
		xargs -i sh -c 'clang-format -i --verbose {} && git add {}'

lint:
	@clang-format -i --verbose \
	$(shell find $(INCLUDE_DIR) $(TESTER_DIR) -name "*.tpp" \
		-o -name "*.hpp" -o -name "*.cpp")

clean-cov:
	@echo "[Cleaning] Coverage Files."
	@rm -rf $(GCNO_FILES) $(GCDA_FILES) $(LCOV_FILE) $(COVERAGE_DIR)

clean-dep:
	@echo "[Cleaning] Dependency Files."
	@rm -f $(DEP)

clean-obj:
	@echo "[Cleaning] Object Files."
	@rm -f $(OBJ) $(OBJ_STD) $(OBJ_BAD) $(PHC_GCH)

clean-log:
	@echo "[Cleaning] Log Files."
	@rm -f $(VALGRIND_LOG) $(TEST_LOG_STD) $(TEST_LOG_FT)

clean: clean-obj clean-dep clean-log clean-cov

fclean: clean
	@echo "[Cleaning] Program Files."
	@rm -f $(NAME) $(NAME_STD)
	@rm -rf $(BUILD_DIR)

re: fclean build

-include $(DEP)
