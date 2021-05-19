INCLUDE_DIRS := ./
CC			 := g++
CFLAGS		 := -I$(INCLUDE_DIRS)

EXENAME		 := assignment1

MAINCPP		 := main.cpp
OBJS		 := myException.o list.o
CPPS		 := $(MAINCPP) myException.cpp list.cpp
EXCEPT		 := myException.cpp myException.h
LIST		 := list.cpp list.h

assignment1: $(MAINCPP) $(OBJS)
		$(CC) -g -o $(EXENAME) $(CPPS) $(CFLAGS)

myException.o: $(EXCEPT)
		$(CC) -c -o $@ $< $(CFLAGS)

list.o: $(LIST)
		$(CC) -c -g -o $@ $< $(CFLAGS)


