FLAGS  = -std=c99 -Wall
SOURCES = ./src/rootlocus.c ./src/nyquist.c ./src/input.c main.c
OBJECTS = rootlocus.o nyquist.o input.o main.o
HEADERS = ./inc/rootlocus.h ./inc/nyquist.h ./inc/input.h ./inc/datatypes.h
EXEBIN  = main

$(EXEBIN) : $(OBJECTS) $(HEADERS)
		gcc -Iinc/ $(OBJECTS) -o $(EXEBIN)

$(OBJECTS) : $(SOURCES) $(HEADERS)
		gcc -Iinc/ -c $(FLAGS) $(SOURCES)

clean :
		rm -f $(EXEBIN) $(OBJECTS)
