COMPILER = g++
FLAGS = -std=c++11 -Wall -g
EXECUTABLE = mmprog


all: Driver.o Mentee.o Mentor.o
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) Driver.o Mentee.o Mentor.o

Driver.o: Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp

Mentee.o: Mentee.cpp
	$(COMPILER) $(FLAGS) -c Mentee.cpp

Mentor.o: Mentor.cpp
	$(COMPILER) $(FLAGS) -c Mentor.cpp

clean:
	rm -rf *.o $(EXECUTABLE) $(EXECUTABLE).dSYM .DS_Store Results.txt

run:
	./$(EXECUTABLE)