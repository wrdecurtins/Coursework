//*********************INCLUDE GUARD*********************
#ifndef __MY_EXCEPTION_H__
#define __MY_EXCEPTION_H__
//*********************INCLUDE GUARD*********************

//*********************REQUIRED INCLUDES*********************
#include <exception>
#include <string>
//*********************REQUIRED INCLUDES*********************

using namespace std;


//*********************START CLASS MyException DEFINITION*********************
class MyException : public exception {
    public:
        MyException(void);
        MyException(const char*);
        MyException(const string&);
        virtual const string what(){
            return this->retrieveError();
        }
    private:
        string errString;
        string retrieveError(void);
};
//*********************END CLASS MyException DEFINITION*********************

#endif