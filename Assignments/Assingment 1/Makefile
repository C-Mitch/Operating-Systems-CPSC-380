BUILD_FLAGS = -w -g -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Assignment1.exe

Assignment6.o: Makefile Assignment6.cpp
	$(CC) $(BUILD_FLAGS) -c Assignment1.cpp -o Assignment1.o
	
GenFileIn.o: Makefile GenFileIn.cpp
	$(CC) $(BUILD_FLAGS) -c GenFileIn.cpp -o GenFileIn.o
	
Assignment1.exe: Makefile Assignment1.o GenFileIn.o Assignment1Driver.cpp
	$(CC) $(BUILD_FLAGS) Assignment1.o GenFileIn.o Assignment1Driver.cpp -o Assignment1.exe
	
clean:
	$(RM) $(EXES) $(OBJECTS)