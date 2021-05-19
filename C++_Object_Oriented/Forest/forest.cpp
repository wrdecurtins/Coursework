#include "forest.h"
#include <fstream>

/**************************** PUBLIC: Constructor ****************************/
forest::forest(void){
	this->numberOfItems = 0;
	this->components = NULL;
}

/**************************** PUBLIC: Destructor ****************************/
forest::~forest(void){
	//destroy components
	free(components);
}

/*****************************************************************************************/


/**************************** PUBLIC: quickUnion ****************************/
void forest::quickUnion(int num1, int num2){
	if (!connected(num1,num2))
		components[num1] = num2;
}

/**************************** PUBLIC: connected ****************************/
bool forest::connected(int num1, int num2){
	num1 = findRoot(num1);
	num2 = findRoot(num2);
	if (num1 == num2)
		return true;
	else
		return false;
}

/**************************** PUBLIC: findRoot ****************************/
int forest::findRoot(int num){
	int i = num;
	while (components[i] != i)
		i = components[i];
	
	return i;
}

/**************************** PUBLIC: createArray ****************************/
void forest::createArray(int N){
	components = (int*) malloc(N * sizeof(int));
	
	for ( int i = 0; i < N; i++ ){
		components[i] = i;
	}
	
	numberOfItems = N;
}

/**************************** PUBLIC: printComponents ****************************/
void forest::printComponents(void){
	for (int i = 0; i < numberOfItems; i++ ){
		cout<<i<<": "<<components[i]<<endl;
	}
}