#include <iostream>
#include "computercourse.h"

using namespace std;

ComputerCourse::ComputerCourse(void){
/*	this->instructorName = "Alex Wollman";
    this->classroomNumber = 107;
    this->building = "Beacom";
*/
	this->setAll("Alex Wollman", 107, "Beacom");
    this->programs[0] = "Ubuntu";
    this->programs[1] = "g++";
    this->programs[2] = "make";
}

ComputerCourse::ComputerCourse(string paramInstructorName, int paramClassroomNumber, string paramBuilding, string paramPrograms[3]) {
/*    this->instructorName = paramInstructorName;
    this->classroomNumber = paramClassroomNumber;
    this->building = paramBuilding;
*/
	this->setAll(paramInstructorName,paramClassroomNumber,paramBuilding);

    for ( int i = 0; i < 3; i++ )
	    if (!paramPrograms[i].empty())
    	    this->programs[i] = paramPrograms[i];
}

ComputerCourse::~ComputerCourse(void){}

