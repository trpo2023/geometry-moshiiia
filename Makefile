FLAGS = -Wall -Werror --std=c++17

USER_DIR_S = build/src

EXECUTABLE = bin/program

TESTS = bin/test

USER_DIR_T = build/test

GTEST_DIR = thirdparty/googletest

GOOGLE_TEST_INCLUDE = thirdparty/googletest/include

GFLAGS += -isystem thirdparty/googletest/include

LDFLAGS += -g -Wall -Wextra -pthread -std=c++17

all: $(EXECUTABLE) $(TESTS)

$(EXECUTABLE): $(USER_DIR_S)/main.o $(USER_DIR_S)/circle.o
	g++ $(FLAGS) $(USER_DIR_S)/main.o $(USER_DIR_S)/circle.o -o $(EXECUTABLE)

$(USER_DIR_S)/main.o: src/main.cpp
	g++ $(FLAGS) -c src/main.cpp -o $(USER_DIR_S)/main.o

$(USER_DIR_S)/circle.o: src/circle.cpp
	g++ $(FLAGS) -c src/circle.cpp -o $(USER_DIR_S)/circle.o

$(USER_DIR_S)/circle.a: $(USER_DIR_S)/circle.o
	ar rcs $@ $^

$(TESTS): $(USER_DIR_T)/circle_test.o  $(USER_DIR_S)/circle.a
	g++ $(GFLAGS) $(LDFLAGS) -L$(GTEST_DIR)/lib -l gtest_main -l gtest -lpthread $(USER_DIR_T)/circle_test.o $(USER_DIR_S)/circle.a -o $(TESTS)


$(USER_DIR_T)/circle_test.o: test/circle_test.cpp
	g++ $(GFLAGS) $(LDFLAGS) -I $(GOOGLE_TEST_INCLUDE) -I src -c test/circle_test.cpp -o $@

clean:
	rm -rf $(USER_DIR_S)/*.o
	rm -rf $(USER_DIR_T)/*.o
	rm -rf bin/*
