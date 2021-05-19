INCLUDE_DIRS := ./files
CC			 := g++
CFLAGS		 := -I$(INCLUDE_DIRS)

codeChallenge1: main.cpp course.o computercourse.o
	$(CC) -o codeChallenge1 main.cpp files/course.cpp files/computercourse.cpp $(CFLAGS)

course.o: files/course.cpp files/course.h
	$(CC) -c -o course.o files/course.cpp $(CFLAGS)

computercourse.o: files/computercourse.cpp files/computercourse.h
	$(CC) -c -o computercourse.o files/computercourse.cpp $(CFLAGS)

