#include "rbTree.h"
#include <fstream>

/**************************** PUBLIC: Constructor ****************************/
rbTree::rbTree(void){
	
}

/**************************** PUBLIC: Destructor ****************************/
rbTree::~rbTree(void){
	
}

/**************************** PUBLIC: createTree ****************************/
RBTREE* rbTree::createTree(int num){
	try{
		struct RBTREE* newTree = new RBTREE;
		tree = newTree;
		tree->value = num;
		tree->color = BLACK;
		tree->parent = NULL;
		tree->left = createNULLNode();
		tree->right = createNULLNode();
		return tree;
	} catch ( exception &exc ){
		string error = string("BAD TREE CREATE: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

/**************************** PUBLIC: createNode ****************************/
RBTREE* rbTree::createNode(int num){
	try{
		struct RBTREE* newNode = new RBTREE;
		newNode->value = num;
		newNode->color = RED;
		newNode->parent = NULL;
		newNode->left = createNULLNode();
		newNode->right = createNULLNode();
		return newNode;
	}catch ( exception &exc ){
		string error = string("BAD NODE CREATE: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

RBTREE* rbTree::createNULLNode(){
	try{
		struct RBTREE* newNode = new RBTREE;
		newNode->value = -1;
		newNode->color = BLACK;
		newNode->right = NULL;
		newNode->left = NULL;	
		
		return newNode;
	}catch ( exception &exc ){
		string error = string("BAD NULL CREATE: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}


/**************************** PUBLIC: createNode ****************************/
RBTREE* rbTree::findNode(int num){
	try{
		struct RBTREE* finder = tree;
		while (finder->value != num){
			//cout<<"find value"<<finder->value<<endl;
			if (finder->value < num)
				finder = finder->right;
			else if (finder->value > num)
				finder = finder->left;
		}
		return finder;
	}catch ( exception &exc ){
		string error = string("BAD FIND NODE: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

/**************************** PUBLIC: insertNode ****************************/
int rbTree::insertNode(int num){
	p_insertNode(num, tree);
}

/**************************** PUBLIC: deleteNode ****************************/
int rbTree::deleteNode(int num){
	p_deleteNode(findNode(num));
	return 0;
}

/*****************************************************************************************/

/**************************** PUBLIC: printTree ****************************/
void rbTree::printTree(void){
	p_printTree(tree);
	cout<<endl;
	p_DumpTree(tree, 0);
}


/**************************** PRIVATE: p_printTree ****************************/
void rbTree::p_printTree(RBTREE *rbtree){
	try{
		cout << rbtree->value;
		if (rbtree->color == RED)
			cout << string(" (R) ");
		else if (rbtree->color == BLACK)
			cout << string(" (B) ");
		cout << string(": ");
		
		if (rbtree->parent != NULL)
			cout << rbtree->parent->value << endl;
		else
			cout << string("ROOT") << endl;

		if (rbtree->right->value != -1){
			p_printTree(rbtree->right);
		}
		if (rbtree->left->value != -1){
			p_printTree(rbtree->left);
		}
	}catch ( exception &exc ){
		string error = string("BAD TREE PRINT: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

/**************************** PRIVATE: insertNode ****************************/

int rbTree::p_insertNode(int num, RBTREE* finder){
	try{
		if (finder->value > num){
			if (finder->left->value != -1)
				p_insertNode(num,finder->left);
			else{
				finder->left = createNode(num);
				finder->left->parent = finder;
				rbColorCheck(finder->left);
			}
		}
		else if (finder->value < num){
			if (finder->right->value != -1)
				p_insertNode(num,finder->right);
			else{
				finder->right = createNode(num);
				finder->right->parent = finder;
				rbColorCheck(finder->right);
			}
		}

		return 0;
	}catch ( exception &exc ){
		string error = string("BAD INSERT: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}


/**************************** PRIVATE: rbColorCheck ****************************/
int rbTree::rbColorCheck(RBTREE* node){
	try{
		RBTREE* uncle = NULL;
		
		while (node->parent->color == RED){
			if (node->parent == node->parent->parent->right){
				uncle = node->parent->parent->left;
				if (uncle->color == RED){
					uncle->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				} else {
					if (node == node->parent->left){
						node = node->parent;
						p_rightRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					p_leftRotate(node->parent->parent);
				}
			} else {
				uncle = node->parent->parent->right;
				
				if (uncle->color == RED){
					uncle->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				} else {
					if (node == node->parent->right){
						node = node->parent;
						p_leftRotate(node);
					}
					
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					p_rightRotate(node->parent->parent);
				}
			}
			if (node->parent == NULL||node->parent->value == -1){
				tree = node;
				break;
			}
		}
		
		tree->color = BLACK;
	} catch ( exception &exc ){
		string error = string("BAD COLOR CHECK: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

/**************************** PRIVATE: p_rightRotate ****************************/
int rbTree::p_rightRotate(RBTREE* node){
	try{		
		RBTREE* leftchild = node->left;
		node->left = leftchild->right;
		
		if (node->left->value != -1){
			node->left->parent = node;
		}
		
		leftchild->parent = node->parent;
		
		if (node->parent == NULL){
			tree = leftchild;
		} else if (node->parent->value == -1){
			tree = leftchild;
		}else if (node == node->parent->right){
			node->parent->right = leftchild;
		} else{
			node->parent->left = leftchild;
		}
		leftchild->right = node;
		node->parent = leftchild;
		
		tree->parent = NULL;
		return 0;
	} catch ( exception &exc ){
		string error = string("BAD RIGHT ROTATE: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

/**************************** PRIVATE: p_leftRotate ****************************/
int rbTree::p_leftRotate(RBTREE* node){
	
	try{
		RBTREE* rightchild = node->right;
		node->right = rightchild->left;

		if (node->right->value != -1){
			node->right->parent = node;
		}
		
		rightchild->parent = node->parent;
		
		if (node->parent == NULL){
			tree = rightchild;
		} else if (node->parent->value == -1){
			tree = rightchild;
		} else if (node == node->parent->left){
			node->parent->left = rightchild;
		} else{
			node->parent->right = rightchild;
		}
		rightchild->left = node;
		node->parent = rightchild;
		
		tree->parent = NULL;
		return 0;
	} catch ( exception &exc ){
		string error = string("BAD LEFT ROTATE: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

/**************************** PRIVATE: deleteNode ****************************/
int rbTree::p_deleteNode(RBTREE* node){
	try{
		RBTREE *node2, *node3;
		node2 = node;
		int node2ogColor = node2->color;
		node2 = node;
		
		if (node->left->value == -1){
			node3 = node->right;
			p_parentSwap(node, node->right);
		} else if (node->right->value == -1){
			node3 = node->left;
			p_parentSwap(node, node->left);
		} else {
			node2 = findMin(node->right);
			node2ogColor = node2->color;
			node3 = node2->right;
			if (node2->parent == node){
				node3->parent = node2;
			}else{
				p_parentSwap(node2,node2->right);
				node2->right = node->right;
				node2->right->parent = node2;
			}
			
			p_parentSwap(node, node2);
			node2->left = node->left;
			node2->left->parent = node2;
			node2->color = node->color;
		}
		
		delete node;
		if (node2ogColor == BLACK){
			p_rbfixdelete(node3);
		}
	}catch ( exception &exc ){
		string error = string("BAD NODE DELETE: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

/**************************** PRIVATE: p_rbfixdelete ****************************/
void rbTree::p_rbfixdelete(RBTREE* node){
	try {
		RBTREE *node2;
		while (node != tree && node->color == BLACK){
			if (node == node->parent->left){
				node2 = node->parent->right;
				if (node2->color == RED){
					node2->color = BLACK;
					node->parent->color = RED;
					p_leftRotate(node->parent);
					node2 = node->parent->right;
				}
				
				if (node2->left->color == BLACK && node2->right->color == BLACK){
					node2->color = RED;
					node = node->parent;
				} else {
					if (node2->right->color == BLACK){
						node2->left->color = BLACK;
						node2->color = RED;
						p_rightRotate(node2);
						node2 = node->parent->right;
					}
					
					node2->color = node->parent->color;
					node->parent->color = BLACK;
					node2->right->color = BLACK;
					p_leftRotate(node->parent);
					node = tree;
				}
			} else {
				node2 = node->parent->left;
				if (node2->color == RED){
					node2->color = BLACK;
					node->parent->color = RED;
					p_rightRotate(node->parent);
					node2 = node->parent->left;
				}
				
				if (node2->right->color == BLACK && node2->right->color == BLACK){
					node2->color = RED;
					node = node->parent;
				} else {
					if (node2->left->color == BLACK){
						node2->right->color = BLACK;
						node2->color = RED;
						p_leftRotate(node2);
						node2 = node->parent->left;
					}
					
					node2->color = node->parent->color;
					node->parent->color = BLACK;
					node2->left->color = BLACK;
					p_rightRotate(node->parent);
					node = tree;
				}
			}
		}
		node->color = BLACK;
	} catch ( exception &exc ){
		string error = string("BAD DELETE FIX: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

/**************************** PRIVATE: p_parentSwap ****************************/
void rbTree::p_parentSwap(RBTREE* a, RBTREE* b){
	try{
		if (a->parent == NULL || a->parent->value == -1){
			tree = b;
		} else if ( a == a->parent->left ){
			a->parent->left = b;
		} else{
			a->parent->right = b;
		}
		b->parent = a->parent;
	} catch ( exception &exc ){
		string error = string("BAD PARENT SWAP: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

/**************************** PRIVATE: findMin ****************************/
RBTREE* rbTree::findMin(RBTREE* node){
	try{
		while (node->left->value != -1){
			node = node->left;
		}
		return node;
	}catch ( exception &exc ){
		string error = string("BAD FIND MIN: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

/**************************** PRIVATE: findMax ****************************/
RBTREE* rbTree::findMax(RBTREE* node){
	try{
		while (node->right->value != -1){
			node = node->right;
		}
		return node;
	}catch ( exception &exc ){
		string error = string("BAD FIND MAX: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}

/************************* PRIVATE: p_DumpTree *************************/
void rbTree::p_DumpTree(RBTREE* node, int indent){
	try{
		if( NULL == node ){
			return;
		} else {
			this->p_DumpTree(node->left, indent+4);
			if( -1 != node->value ){
				if( indent ){
					cout<<setw(indent)<<" ";
				}
				cout<<node->value<<": ";
				if( BLACK == node->color ){
					cout<<"BLACK"<<endl;
				} else {
					cout<<"RED"<<endl;
				}
			}
			this->p_DumpTree(node->right, indent+4);
		}
	}catch ( exception &exc ){
		string error = string("BAD TREE DUMP: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
}