FLAGS  = -std=c99 -Wall
SOURCES = rootlocus.c nyquist.c main.c
OBJECTS = rootlocus.o nyquist.o main.o
HEADERS = rootlocus.h nyquist.h datatypes.h
EXEBIN  = main

$(EXEBIN) : $(OBJECTS) $(HEADERS)
		gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES) $(HEADERS)
		gcc -c $(FLAGS) $(SOURCES)

clean :
		rm -f $(EXEBIN) $(OBJECTS)
