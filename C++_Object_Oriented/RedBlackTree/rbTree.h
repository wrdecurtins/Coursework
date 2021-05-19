#ifndef __RBTREE__H__
#define __RBTREE__H__

#include <iostream>
#include <iomanip>

using namespace std;

const int BLACK = 0;
const int RED = 1;

typedef struct RBTREE{
	int value;
	int color;
	RBTREE *parent;
	RBTREE *left;
	RBTREE *right;
}s_RBTREE;

class rbTree{
	public:
		rbTree(void);
		~rbTree(void);
		RBTREE* createTree(int num);
		RBTREE* createNode(int num);
		RBTREE* createNULLNode();
		RBTREE* findNode(int num);
		int insertNode(int num);
		int deleteNode(int num);
		void printTree(void);

		
	private:
		RBTREE *tree;
		RBTREE *nullNODE;
		int rbColorCheck(RBTREE* node);
		int p_insertNode(int num, RBTREE* finder);
		void p_printTree(RBTREE* rbtree);
		int p_rightRotate(RBTREE* node);
		int p_leftRotate(RBTREE* node);
		int p_deleteNode(RBTREE* node);
		void p_rbfixdelete(RBTREE* node);
		void p_parentSwap(RBTREE* a, RBTREE* b);
		RBTREE* findMin(RBTREE* node);
		RBTREE* findMax(RBTREE* node);
		void p_DumpTree(RBTREE* node, int indent);
};

#endif