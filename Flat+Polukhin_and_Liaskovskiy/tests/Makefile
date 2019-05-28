.PHONY: all clean
CC = g++
CPPFLAGS = -c -Wall
OBJECTS = Action.o Apartment.o Door.o Flat.o Furniture.o Hall.o Point.o Robot.o Room.o Target.o Task.o Wall.o Way.o

all: Flat_test

clean:
	rm -rf Flat_test *.o

Flat_test: Flat_test.o $(OBJECTS)
	$(CC) -o Flat_test Flat_test.o $(OBJECTS)

Flat_test.o: Flat_test.cpp
	$(CC) $(CPPFLAGS) -o Flat_test.o Flat_test.cpp

$(OBJECTS): 
%.o: ../src/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@