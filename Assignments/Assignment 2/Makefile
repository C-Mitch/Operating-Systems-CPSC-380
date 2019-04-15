BUILD_FLAGS = -w -g -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: SeeSaw.exe
	
Simulation.o: Makefile Simulation.cpp
	$(CC) $(BUILD_FLAGS) -c Simulation.cpp -o Simulation.o
	
SeeSaw.exe: Makefile Simulation.o Driver.cpp
	$(CC) $(BUILD_FLAGS) Simulation.o Driver.cpp -o SeeSaw.exe
	
clean:
	$(RM) $(EXES) $(OBJECTS)