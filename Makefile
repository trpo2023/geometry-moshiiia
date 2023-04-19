CXX = g++
CXXFLAGS = -I src -Wall -Wextra -std=c++11

SRC_DIR = src
OBJ_DIR = obj
SRCS = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

TESTS_DIR = test
TEST_OBJ = obj
GTEST_DIR = thirdparty/googletest
GOOGLE_TEST_DIR = thirdparty/googletest/include
GFLAGS += -isystem thirdparty/googletest/include
LDFLAGS += -g -Wall -Wextra -pthread -std=c++17

all: main tests

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test: $(TEST_OBJ)/circle_test.o  $(OBJ_DIR)/Circle.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -L$(GTEST_DIR)/lib -l gtest_main -lpthread $(TEST_OBJ)/circle_test.o $(OBJ_DIR)/Circle.o  -o $(TESTS)


$(USER_DIR_T)/leaderboard_test.o: test/leaderboard_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/leaderboard_test.cpp -o $@

$(USER_DIR_T)/menu_test.o: test/menu_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/menu_test.cpp -o $@

$(USER_DIR_T)/sequence_test.o: test/sequence_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/sequence_test.cpp -o $@

$(USER_DIR_T)/game_test.o: test/game_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/game_test.cpp -o $@

clean:
	rm -rf $(USER_DIR_S)/*.o
	rm -rf $(USER_DIR_T)/*.o
	rm -rf bin/*



$(USER_DIR_T)/leaderboard_test.o: test/leaderboard_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/leaderboard_test.cpp -o $@

$(USER_DIR_T)/menu_test.o: test/menu_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/menu_test.cpp -o $@

$(USER_DIR_T)/sequence_test.o: test/sequence_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/sequence_test.cpp -o $@

$(USER_DIR_T)/game_test.o: test/game_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/game_test.cpp -o $@


go:
	./main
clean:
	rm -rf $(OBJ_DIR) main

.PHONY: all clean
