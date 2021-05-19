//*********************INCLUDE GUARD*********************//
#ifndef __COMPUTER_COURSE_H__
#define __COMPUTER_COURSE_H__
//*********************INCLUDE GUARD*********************//

//*********************REQUIRED INCLUDES*********************//
#include <string>
#include "course.h"
//*********************REQUIRED INCLUDES*********************//

using namespace std;

//*********************START CLASS ComputerCourse DEFINITION*********************//
class ComputerCourse : public Course {
	public:

		ComputerCourse(void);
/*		{
			this->instructorName = "Alex Wollman";
            this->classroomNumber = 107;
            this->building = "Beacom";
			this->programs[0] = "Ubuntu";
			this->programs[1] = "g++";
			this->programs[2] = "make";
		};
*/
		ComputerCourse(string paramInstructorName, int paramClassroomNumber, string paramBuilding, string paramPrograms[3]);
/*		{
			this->instructorName = paramInstructorName;
            this->classroomNumber = paramClassroomNumber;
            this->building = paramBuilding;

			for ( int i = 0; i < 3; i++ )
				if (paramPrograms[i] != NULL)
					this->programs[i] = paramPrograms[i];
		};
*/
		~ComputerCourse(void);
		void virtual printAll()
		{
			cout<< "Instructor Name  : " << this->getinstructorName() << "\n";
            cout<< "Classroom Number : " << this->getclassroomNumber() << "\n";
            cout<< "Building Name    : " << this->getbuilding() << "\n";

			if (!this->programs[0].empty())
				cout<< "Programs Used    : ";

			for ( int i = 0; i < 3; i++ )
			{
				if (!this->programs[i].empty())
				{
					cout<< this->programs[i] << " ";
				}
			}
		}
	private:
		string programs[3];
};
//*********************END CLASS ComputerCourse DEFINITION*********************

#endif
