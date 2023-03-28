APP=Projectrpo3
CC=gcc
CFLAGS = -Wall -Werror
CPPFLAGS = -MMD

SRC_DIR = src/geometry
LIB_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC)) 

$(APP) : $(OBJ)
	$(CC) $(OBJ) -o $(APP)

$(OBJ_DIR)/main.o : $(SRC_DIR)/main.cpp 
	$(CC) $(SRC_DIR)/main.cpp -o  -I $(LIB_DIR) $(OBJ_DIR)/main.o $(CPPFLAGS)


$(OBJ_DIR)/Circle.o : $(SRC_DIR)/Circle.cpp 
	$(CC) -c $< -o -I $(LIB_DIR) $@ $(CPPFLAGS)


$(OBJ_DIR)/Point.o : $(SRC_DIR)/Point.cpp 
	$(CC) -c $< -o -I $(LIB_DIR) $@ $(CPPFLAGS)

#общий вид
#$(SRC_DIR)/%.o : $(OBJ_DIR)/%.cpp\
#	$(CC) -c $< -o $@ $(FLAGS)\
#$<- слева $@ - справа



go:
	./$(APP)

clean:
	rm $(APP) $(OBJ_DIR)/*.o 

.PHONY: clean
