PROJECT := SecondAssignment
CC :=g++
CCVERSION = -std=c++11
CCFLAGS = $(CCVERSION) -g

LIBS :=-lfreeglut -lglew32 -lopengl32 -lglu32

SRC_DIR := src
SRC_INCLUDE := include
SRC_INCLUDE_2DEPTH := ${SRC_INCLUDE}/Alex
INCLUDE := -I ${SRC_INCLUDE} -I ${SRC_INCLUDE_2DEPTH}

# Default target executed when no arguments are given to make.
.DEFAULT_GOAL: all

%.o: src/%.cc
	$(CC)	$(CCFLAGS)	-c $<	-o bin/$@

all: $(SRC_DIR)
	$(CC)	$(CCFLAGS) -o $(PROJECT) $(INCLUDE)	$(SRC_DIR)/*.cc $(LIBS)

run: all
	./$(PROJECT).exe

clean:
	rm -f *~ bin/*.o
