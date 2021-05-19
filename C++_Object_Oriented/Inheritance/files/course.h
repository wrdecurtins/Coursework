//*********************INCLUDE GUARD*********************//
#ifndef __COURSE_H__
#define __COURSE_H__
//*********************INCLUDE GUARD*********************//

//*********************REQUIRED INCLUDES*********************//
#include <string>
//*********************REQUIRED INCLUDES*********************//

using namespace std;

//*********************START CLASS Course DEFINITION*********************//
class Course {
	public:

		Course(void);
/*		{
			this->instructorName = "Alex Wollman";
			this->classroomNumber = 107;
			this->building = "Beacom";
		};
*/
		Course(string paramInstructorName, int paramClassroomNumber, string paramBuilding);
/*		{
			this->instructorName = paramInstructorName;
			this->classroomNumber = paramClassroomNumber;
			this->building = paramBuilding;
		};
*/
		~Course(void);
		void printAll()
		{
			cout<< "Instructor Name  : " << this->instructorName << "\n";
			cout<< "Classroom Number : " << this->classroomNumber << "\n";
			cout<< "Building Name	 : " << this->building << "\n";
		}
	protected:
		string getinstructorName(){
			return this->instructorName;
		}
		int getclassroomNumber(){
			return this->classroomNumber;
		}
		string getbuilding(){
			return this->building;
		}
		void setAll(string setInstructorName, int setClassroomNumber, string setBuilding)
		{
			this->instructorName = setInstructorName;
			this->classroomNumber = setClassroomNumber;
			this->building = setBuilding;
		}
	private:
		string instructorName;
		int classroomNumber;
		string building;
};
//*********************END CLASS Course DEFINITION*********************

#endif
