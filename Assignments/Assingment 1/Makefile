BUILD_FLAGS = -w -g -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: SVP.exe
	
GenIn.o: Makefile GenIn.cpp
	$(CC) $(BUILD_FLAGS) -c GenIn.cpp -o GenIn.o
	
SVP.exe: Makefile GenIn.o Assignment1Driver.cpp
	$(CC) $(BUILD_FLAGS) GenIn.o Assignment1Driver.cpp -o SVP.exe
	
clean:
	$(RM) $(EXES) $(OBJECTS)