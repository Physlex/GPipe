PROJECT := LearnOpenGl

CC :=g++
CFLAGS :=-Iinclude -std=c++11 -g

SRC_DIR := src
SRC_INCLUDE := include
INCLUDE := -I ${SRC_INCLUDE}
LIBS :=-lfreeglut -lglew32 -lopengl32 -lglu32

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

%.o: src/%.cc
	$(CC)	$(CFLAGS)	-c $<	-o bin/$@

all: $(SRC_DIR)
	$(CC)	$(CFLAGS) -o $(PROJECT)	$(SRC_DIR)/*.cc $(LIBS)

run: all
	./$(PROJECT).exe

clean:
	rm -f *~ bin/*.o
