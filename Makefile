# COMPILER
CXX	=	g++

# BINARY NAME
BINARY		=	my_doom

# DIRECTORIES
INCLUDE_DIR	=	include
SRC_DIR		=	src
OBJ_DIR		=	build

# HEADERS
INCLUDE_FILES	=	$(shell find $(INCLUDE_DIR) -type d)
INCLUDE_FLAGS	=	$(addprefix -I, $(INCLUDE_FILES))

# FILES
SRC_FILES	=	$(shell find $(SRC_DIR) -name "*.cpp")
OBJ_FILES	=	$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# SUBDIRECTORIES
OBJ_SUBDIRS	=	$(sort $(dir $(OBJ_FILES) $(TEST_OBJ_FILES)))

# FLAGS
CXXFLAGS	=	$(INCLUDE_FLAGS) -Wall -Werror -Wextra -W -std=c++20 -g3
LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TESTSFLAGS	=	--coverage -lcriterion

all: $(BINARY)

run: re
	./$(BINARY)

$(BINARY): $(OBJ_FILES)
	$(CXX) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR) $(OBJ_SUBDIRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_SUBDIRS):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) *.vgcore

fclean: clean
	$(RM) $(BINARY)
	$(RM) $(BINARY_TEST)

re: fclean all

.PHONY: all clean fclean re run
