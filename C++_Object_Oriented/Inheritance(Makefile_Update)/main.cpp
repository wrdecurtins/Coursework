#include <iostream>
#include "course.h"
#include "computercourse.h"

using namespace std;

int main(int argc, char* argv[])
{
	string examplePrograms[3] = {"VSCode","KDBG","gcc"};

	Course courseExample("Alex",117,"Beacom");

	ComputerCourse computerCourseExample("Alex",117,"Beacom",examplePrograms);

	cout << "Base class Course example-------------------\n";
	courseExample.printAll();

	cout << "\nDerived class ComputerCourse example--------\n";
	computerCourseExample.printAll();
	cout << "\n";


	return 0;
}
