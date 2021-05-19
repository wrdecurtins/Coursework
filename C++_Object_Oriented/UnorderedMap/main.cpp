#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

class MyException : public exception {
	public:
		MyException(const string &err){
			this->errString = err;
		}
		virtual const string what(){
			return this->errString;
		}
	private:
		string errString;
};

int main(int argc, char *argv[]){

	unordered_map<int, int> myMap;
    unordered_map<int, int>::iterator mapIterator;
	
	int valueSize, numElements, temp, i;
	fstream myInput;
	
	myInput.open("input.txt", ios::in);
	myInput >> numElements;
	myInput >> valueSize;

	for (i = 0; i < valueSize; i++ )
	{
		myMap.insert(pair<int, int> (i,0));
	}


	for (i = 0; i < numElements; i++ )
	{
		myInput >> temp;
		if ( temp < valueSize && temp >= 0 ){
			myMap[temp] = myMap[temp] + 1;
		}
		else{
			MyException exc("ERROR: ILLEGAL INSERTION");
			cout<<exc.what()<<endl;
			throw exc;
		}
	}
	
	for( mapIterator = myMap.begin(); mapIterator != myMap.end(); ++mapIterator){
        cout<<mapIterator->first<<": "<<mapIterator->second<<endl;
    }


	return 0;
}