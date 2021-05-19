INCLUDE_DIRS := ./
CC			 := g++
CFLAGS		 := -I$(INCLUDE_DIRS)

OBJS		 := rbTree.o
CPPS		 := rbTree.cpp
TREE		 := rbTree.cpp rbTree.h

assignment1: main.cpp $(OBJS)
		$(CC) -g -o assignment2 main.cpp $(CPPS) $(CFLAGS)

rbTree.o: $(TREE)
		$(CC) -c -o $@ $< $(CFLAGS)