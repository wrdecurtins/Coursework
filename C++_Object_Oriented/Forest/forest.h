#ifndef __FOREST__H__
#define __FOREST__H__

#include <iostream>

using namespace std;

class forest{
	public:
		forest(void);
		~forest(void);
		void quickUnion(int num1, int num2);
		bool connected(int num1, int num2);
		int findRoot(int num);
		void createArray(int N);
		void printComponents(void);

	private:
		int *components;
		int numberOfItems;
};

#endif