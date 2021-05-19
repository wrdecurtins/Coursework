INCLUDE_DIRS := ./files
CC			 := g++
CFLAGS		 := -I$(INCLUDE_DIRS)
INC			 := $(INCLUDE_DIRS)/

EXENAME		 := codeChallenge2

MAINCPP		 := main.cpp
OBJS		 := course.o computercourse.o
CPPS		 := $(MAINCPP) $(INC)course.cpp $(INC)computercourse.cpp
COURSE		 := $(INC)course.cpp $(INC)course.h
COMPCOURSE	 := $(INC)computercourse.cpp $(INC)computercourse.h

codeChallenge1: $(MAINCPP) $(OBJS)
	$(CC) -o $(EXENAME) $(CPPS) $(CFLAGS)

course.o: $(COURSE)
	$(CC) -c -o $@ $< $(CFLAGS)

computercourse.o: $(COMPCOURSE)
	$(CC) -c -o $@ $< $(CFLAGS)

