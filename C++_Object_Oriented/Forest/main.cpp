#include "forest.h"
#include <fstream>

int main(int argc, char *argv[]){
	
	forest Forest;
	
	Forest.createArray(16);
	
	Forest.quickUnion(1,0);
	Forest.quickUnion(10,9);
	Forest.quickUnion(9,5);
	Forest.quickUnion(11,12);
	Forest.quickUnion(12,5);
	Forest.quickUnion(7,6);
	Forest.quickUnion(6,2);
	Forest.quickUnion(3,2);
	Forest.quickUnion(8,4);
	Forest.quickUnion(14,15);
	Forest.quickUnion(15,13);
	
	Forest.printComponents();
	
	
	return 0;
}