#include "rbTree.h"
#include <fstream>

int main(int argc, char *argv[]){

	fstream input;
	int inputCount, i, inputValue;
	struct rbTree* RBtree = new rbTree;
	
	cout<<"*********Importing*********"<<endl;
	
	input.open("inputValues.txt", ios::in);
	input >> inputCount;

	input >> inputValue;
	cout << inputValue << endl;
	RBtree->createTree(inputValue);

	for ( i = 0; i < inputCount - 1; i++ )
	{
		input >> inputValue;
		cout << inputValue << endl;
		RBtree->insertNode(inputValue);
	}

	RBtree->deleteNode(33);
	RBtree->deleteNode(70);
	RBtree->deleteNode(50);
	RBtree->deleteNode(20);

	input.close();
	cout<<"*********ClosingFile*********"<<endl;

	RBtree->printTree();

	return 0;
}