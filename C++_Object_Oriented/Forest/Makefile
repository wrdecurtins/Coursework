INCLUDE_DIRS := ./
CC			 := g++
CFLAGS		 := -I$(INCLUDE_DIRS)

EXENAME		 := codeChallenge3

MAINCPP		 := main.cpp
OBJS		 := forest.o
CPPS		 := $(MAINCPP) forest.cpp
FOREST		 := forest.cpp forest.h

assignment1: $(MAINCPP) $(OBJS)
		$(CC) -g -o $(EXENAME) $(CPPS) $(CFLAGS)

forest.o: $(FOREST)
		$(CC) -c -o $@ $< $(CFLAGS)