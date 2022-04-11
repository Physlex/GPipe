PROJECT := SecondAssignment
CC :=g++
CCVERSION = -std=c++11
CCFLAGS = $(CCVERSION) -g

LIBS :=-lfreeglut -lglew32 -lopengl32 -lglu32

SRC_DIR := src
PROJECT_DIR := ${SRC_DIR}/project
TEST_DIR := test
SRC_INCLUDE := include
SRC_INCLUDE_ALEX := ${SRC_INCLUDE}/Alex
SRC_INCLUDE_ANGEL := ${SRC_INCLUDE}/Angel

INCLUDE := -I ${SRC_INCLUDE_ANGEL} -I ${SRC_INCLUDE_ALEX}

# Default target executed when no arguments are given to make.
.DEFAULT_GOAL: all

%.o: src/%.cc
	$(CC)	$(CCFLAGS)	-c $<	-o bin/$@

all: $(SRC_DIR) $(PROJECT_DIR)
	$(CC)	$(CCFLAGS) -o $(PROJECT) $(INCLUDE) $(SRC_DIR)/*.cc $(PROJECT_DIR)/*.cc $(LIBS)

test: $(SRC_DIR) $(TEST_DIR)
	$(CC) $(CCFLAGS) -o $(PROJECT) $(INCLUDE) $(SRC_DIR)/*.cc $(TEST_DIR)/*.cc $(LIBS)

run: all
	./$(PROJECT).exe

clean:
	rm -f *~ bin/*.o
