#include <iostream>
#include "course.h"

using namespace std;

Course::Course(void){
	this->instructorName = "Alex Wollman";
    this->classroomNumber = 107;
    this->building = "Beacom";
}

Course::Course(string paramInstructorName, int paramClassroomNumber, string paramBuilding) {
    this->instructorName = paramInstructorName;
    this->classroomNumber = paramClassroomNumber;
    this->building = paramBuilding;
}

Course::~Course(void){}
