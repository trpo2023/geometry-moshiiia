all: main
main: main.cpp
	g++ main.cpp -o main -Wall -Werror
go:
	./main
