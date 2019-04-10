BUILD_FLAGS = -w -g -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: SVP.exe
	
Simulation.o: Makefile Simulation.cpp
	$(CC) $(BUILD_FLAGS) -c Simulation.cpp -o Simulation.o
	
SVP.exe: Makefile Simulation.o Driver.cpp
	$(CC) $(BUILD_FLAGS) Simulation.o Driver.cpp -o SVP.exe
	
clean:
	$(RM) $(EXES) $(OBJECTS)