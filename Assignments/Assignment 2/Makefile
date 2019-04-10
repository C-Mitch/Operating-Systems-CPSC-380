BUILD_FLAGS = -w -g -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: SS.exe
	
Simulation.o: Makefile Simulation.cpp
	$(CC) $(BUILD_FLAGS) -c Simulation.cpp -o Simulation.o
	
SS.exe: Makefile Simulation.o Driver.cpp
	$(CC) $(BUILD_FLAGS) Simulation.o Driver.cpp -o SS.exe
	
clean:
	$(RM) $(EXES) $(OBJECTS)