FLAGS  = -std=c99 -Wall
SOURCES = rootlocus.c  main.c
OBJECTS = rootlocus.o  main.o
HEADERS = rootlocus.h
EXEBIN  = main

$(EXEBIN) : $(OBJECTS) $(HEADERS)
		gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES) $(HEADERS)
		gcc -c $(FLAGS) $(SOURCES)

clean :
		rm -f $(EXEBIN) $(OBJECTS)
