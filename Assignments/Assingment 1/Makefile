BUILD_FLAGS = -w -g -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: SVP.exe

Assignment6.o: Makefile Assignment6.cpp
	$(CC) $(BUILD_FLAGS) -c Assignment1.cpp -o Assignment1.o
	
GenIn.o: Makefile GenIn.cpp
	$(CC) $(BUILD_FLAGS) -c GenIn.cpp -o GenIn.o
	
SVP.exe: Makefile Assignment1.o GenIn.o Assignment1Driver.cpp
	$(CC) $(BUILD_FLAGS) Assignment1.o GenIn.o Assignment1Driver.cpp -o SVP.exe
	
clean:
	$(RM) $(EXES) $(OBJECTS)