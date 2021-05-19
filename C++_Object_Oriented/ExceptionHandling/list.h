#ifndef __LIST__H__
#define __LIST__H__

#include <iostream>

using namespace std;

typedef struct NODE{
    int value;
    NODE *next;
    NODE *previous;
}s_NODE;

class list{
    public:
        list();
        ~list();
        int appendValue(int myValue);
        int deleteList(s_NODE* head);
        int findValue(int valueToFind);
        void printList(void);
        int removeValue(int valueToRemove);
        void sortList(void);
		void printValue(int valueToPrint);


    private:
        int p_IsSorted;
        int p_NumberOfNodes;
        s_NODE *p_Head;

        s_NODE* p_CreateNode(int myValue);
        int p_DeleteList(s_NODE* head);
        int p_DeleteNode(s_NODE* deleteNode);
        int p_InsertNode(s_NODE* node);
		void p_PrintList(void);
		void p_PrintValue(int valueToPrint);
		s_NODE* p_FindValue(int valueToFind);
		s_NODE* p_GetHead(void);

};

#endif