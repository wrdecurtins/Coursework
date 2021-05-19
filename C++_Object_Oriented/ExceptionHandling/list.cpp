#include "list.h"
#include "myException.h"

/**************************** PUBLIC: Constructor ****************************/
/*
    Implementation hint(s): should initialize variables.
*/
list::list(void){
	this->p_Head = NULL;
	this->p_IsSorted = 0; 		// not sorted
	this->p_NumberOfNodes = 0;
}

/**************************** PUBLIC: Destructor ****************************/
/*
    Implementation hint(s): Should ensure all dynamically allocated memory is deleted.
*/
list::~list(void){
	this->deleteList(p_GetHead());
}


/*****************************************************************************************/



/**************************** PUBLIC: appendValue ****************************/
/*
    Implementation hint(s): invoke relevant member functions to append value to end of list.
*/
int list::appendValue(int myValue){

	int retValue = 0;

	//cout<<"appendbegin"<<endl;

	s_NODE *node = NULL;
	
	if ( 0 >= myValue ){
		MyException exc("WARNING: INVALID VALUE APPEND ATTEMPT");
		cout<<exc.what()<<endl;
		retValue = 1;
	} else {
		try{
			node = this->p_CreateNode(myValue);
		} catch (MyException &exc ){
			cout<<exc.what()<<endl;
			retValue = 1;
		}
		
		if ( p_GetHead() == NULL ){
			p_Head = node;
			p_NumberOfNodes = 1;
		} else {
			try{
				//cout<<"try insert"<<endl;
				p_InsertNode(node);
			} catch (MyException &exc){
				string error = "WARNING: BAD INSERT " + exc.what();
				cout<<error<<endl;
				retValue = 1;
			}
		}
	}
	
	//cout<<"appendend"<<endl;
	
	return retValue;

}

/**************************** PUBLIC: deleteList ****************************/
/*
    Implementation hint(s): invoke relevant member functions to delete the entire list.
*/
int list::deleteList(s_NODE* head){
	int retValue = 0;
	if (head == NULL){
		MyException exc("WARNING: NO LIST TO DELETE");
		cout<<exc.what()<<endl;
		retValue = 1;
	} else {
		retValue = this->p_DeleteList(head);
	}
	return retValue;
}

/**************************** PUBLIC: findValue ****************************/
/*
    Implementation hint(s): invoke relevant member functions to determine if node value is in list or not and notify user.
*/
int list::findValue(int valueToFind){
	int retValue = 0;
	try{
		if (this->p_FindValue(valueToFind) == NULL){
			retValue = 1;
		}
		else {
			
		}
	} catch (MyException &exc){
		cout<<"FIND VALUE FAILURE:"<<exc.what()<<endl;
		retValue = 1;
	}
	
	return retValue;
}

/**************************** PUBLIC: printList ****************************/
/*
    Implementation hint(s): invoke relevant member functions to print the list to the screen. 
*/
void list::printList(void){
	this->p_PrintList();
}

/**************************** PUBLIC: removeValue ****************************/
/*
    Implementation hint(s): invoke relevant member functions to delete value from list.
*/
int list::removeValue(int valueToRemove){
	int retValue = 0;
	s_NODE* deleteNode;
	
	deleteNode = this->p_FindValue(valueToRemove);
	
	if (deleteNode == NULL){
		MyException exc("WARNING: REMOVAL OF A VALUE THAT DOES NOT EXIST ATTEMPTED");
		cout<<exc.what()<<endl;
	} else {
		retValue = this->p_DeleteNode(deleteNode);
	}
	
	return retValue;
}

/**************************** PUBLIC: sortList ****************************/
void list::printValue(int valueToPrint){
	p_PrintValue(valueToPrint);
}

/**************************** PUBLIC: sortList ****************************/
/*
    Implementation hint(s): invoke relevant member functions to sort the list from smallest to largest.
*/
void list::sortList(void){
	s_NODE *left;
	s_NODE *right;
	s_NODE *temp;
	
	left = p_Head;
	right = p_Head->next;
	
	for (int i = p_NumberOfNodes - 1; i > 0; i-- ){
		left = p_Head;
		right = p_Head->next;
		
		for (int k = 0; k < i; k++ ){
			if (right->value < left->value) {
				if (left == p_Head)
					p_Head = right;
				left->next = right->next;
				right->previous = left->previous;
				if (right != p_Head)
					left->previous->next = right;
				if ( right->next != NULL )
					right->next->previous = left;
				left->previous = right;
				right->next = left;
				
				temp = right;
				right = left;
				left = temp;
			} 
			//else {
				right = right->next;
				left = left->next;
			//}
			//printList();
		}			
	}
		

}


/*****************************************************************************************/



/**************************** PRIVATE: p_CreateNode ****************************/
/*
    Implementation hint(s): invoke relevant member functions to create a node given a value.
*/
s_NODE* list::p_CreateNode(int myValue){

	//cout<<"createbegin"<<endl;

	s_NODE *node = NULL;
	
	try{
		node = new s_NODE;
		node->value = myValue;
		node->next = NULL;
		node->previous = NULL;
		
	} catch ( bad_alloc &exc ){
		string error = string("ALLOC FAILURE: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	} catch ( exception &exc ){
		string error = string("GENERAL FAILURE: ") + exc.what();
		cout<<error<<endl;
		throw exc;
	}
	
	//cout<<"createend"<<endl;
	return node;
}

/**************************** PRIVATE: p_DeleteList ****************************/
/*
    Implementation hint(s): invoke relevant member functions to delete the entire list.
*/
int list::p_DeleteList(s_NODE* head){
	int retValue = 0;
	
	if (head == NULL)
		return retValue;
	
	retValue = this->p_DeleteList(head->next);
	
	retValue += p_DeleteNode(head);
	
	return retValue;
}

/**************************** PRIVATE: p_DeleteNode ****************************/
/*
    Implementation hint(s): invoke relevant member functions to delete a given node.
*/
int list::p_DeleteNode(s_NODE* deleteNode){
	
	//cout<<"delete"<<endl;
	
	int retValue = 0;
	
	if ( deleteNode == NULL ){
		MyException exc("WARNING: DELETION OF A NODE THAT DOES NOT EXIST ATTEMPTED");
		cout<<exc.what()<<endl;
		retValue = 1;
	} else if ( deleteNode == p_Head ){
		p_Head = deleteNode->next;
		free(deleteNode);
		p_NumberOfNodes--;
	} else {
	
		s_NODE *previousNode = NULL;
		s_NODE *nextNode = NULL;
		
		previousNode = deleteNode->previous;
		nextNode = deleteNode->next;
		
		previousNode->next = nextNode;
		if ( nextNode != NULL )
			nextNode->previous = previousNode;
		
		free(deleteNode);
		p_NumberOfNodes--;
	}
	
	//cout<<"enddelete"<< endl;
	
	return retValue;
}

/**************************** PRIVATE: p_InsertNode ****************************/
/*
    Implementation hint(s): invoke relevant member functions to insert a given value into the lis.
*/
int list::p_InsertNode(s_NODE* node){
	int retValue = 0;
	
	//cout<<"insert"<<endl;
	
	if ( node == NULL ){
		MyException exc("WARNING: INSERTION OF AN EMPTY NODE ATTEMPTED");
		cout<<exc.what()<<endl;
		retValue = 1;
	} else {
		try {
			//cout<<"attempt insert"<<endl;
			s_NODE *ogFirst;
			ogFirst = p_Head;
			node->next = ogFirst;
			ogFirst->previous = node;
			p_Head = node;
			//cout<<"finish insert"<<endl;
			
			p_NumberOfNodes++;
			p_IsSorted = 1;
			
		} catch ( exception &exc ) {
			string error = string("INSERTION FAILURE: ") + exc.what();
			cout<<error<<endl;
			throw exc;
			retValue = 1;
		}
	}	

	return retValue;
}

/**************************** PRIVATE: p_PrintList ****************************/
void list::p_PrintList(void){
	if ( NULL == this->p_Head ){
		MyException exc("WARNING: LIST TO PRINT IS EMPTY");
		cout<<exc.what()<<endl;
	} else {
		int i = 0;
		s_NODE *travel = p_Head;
		cout<<"*******************PRINTING LIST*******************"<<endl;
		for( i = 0; i < this->p_NumberOfNodes; i++ ){
			if ( NULL == travel ){
				MyException exc("WARNING: NODE IN PRINT LIST IS EMPTY");
				cout<<exc.what()<<endl;
			} else {
				cout<<travel->value<<endl;
				travel = travel->next;
			}
		} 
	}
}

/**************************** PRIVATE: p_FindValue ****************************/
s_NODE* list::p_FindValue(int valueToFind){
	s_NODE *scanner, *retNode;
	retNode = NULL;
	scanner = this->p_Head;
	for ( int i = 0; i < p_NumberOfNodes; i++ ){
		if (scanner->value == valueToFind)
			retNode = scanner;
		scanner = scanner->next;
	}
	
	return retNode;
}

/**************************** PRIVATE: p_GetHead ****************************/
s_NODE* list::p_GetHead(void){
	s_NODE *retValue;
	
	retValue = p_Head;
	
	return retValue;
}

/**************************** PRIVATE: p_PrintValue ****************************/
void list::p_PrintValue(int valueToPrint){
	s_NODE *printNode;
	
	printNode = NULL;
	
	printNode = this->p_FindValue(valueToPrint);
	
	if ( printNode == NULL ){
		MyException exc("WARNING: PRINTING A VALUE THAT DOES NOT EXIST ATTEMPTED");
		cout<<exc.what()<<endl;
	} else {
		cout<<"***PRINTING VALUE***"<<endl;
		cout<<printNode->value<<endl;
	}

}
