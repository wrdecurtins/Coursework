#include "list.h"

#include <fstream>

int main(int argc, char *argv[]){

    fstream myInput;
    int inputCount, i, numFromFile = 0;
	struct list* myList = (struct list*) malloc(sizeof(struct list));

	cout<<"*********Importing*********"<<endl;

    myInput.open("input.txt", ios::in);
    myInput >> inputCount;

    for( i = 0; i < inputCount; ++i ){
        myInput >> numFromFile;
        cout<<numFromFile<<endl;
		myList->appendValue(numFromFile);
    }
    myInput.close();

    //    TODO: insert code here to achieve the below.
    //    Implement the following in code after the initial list has been read in.

    //        sort the list.
	myList->sortList();
	
	//        Print the list.
	myList->printList();
	
    //       append the values found in 'input2.txt' using the above code as a template.

	cout<<"*********Importing*********"<<endl;

	myInput.open("input2.txt", ios::in);
    myInput >> inputCount;

    for( i = 0; i < inputCount; ++i ){
        myInput >> numFromFile;
        cout<<numFromFile<<endl;
		myList->appendValue(numFromFile);
    }
    myInput.close();

    //        Attempt to delete the following values: 10, 3, 52, 2

	//myList->appendValue(-1);
	myList->removeValue(10);
	myList->removeValue(3);
	myList->removeValue(52);
	myList->removeValue(2);

	myList->printList();

    //        Attempt to print the following values: 1, 5, 10, 32
	myList->printValue(1);
	myList->printValue(5);
	myList->printValue(10);
	myList->printValue(32);

    //        sort the remaining list.

	myList->sortList();

    //        print the remaining list to the screen.
	
	myList->printList();


    return 0;
}