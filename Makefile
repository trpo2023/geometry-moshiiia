CXX = g++
CXXFLAGS = -I src -Wall -Wextra -std=c++11
 
SRC_DIR = src
OBJ_DIR = obj
SRCS = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
 
all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
 
go:
	./main
 
clean:
	rm -rf $(OBJ_DIR) main
 
CFLAG += -isystem thirdparty/googletest/include
LD_FLAGS = -L thirdparty/googletest/lib -lgtest_main -lpthread


test : $(OBJ_DIR)/geometry/Circle.o
	$(CXX) $(CFLAG) $(LD_FLAGS) $(OBJ_DIR)/geometry/Circle.o -o geometry_tests
 
.PHONY: all clean test
 