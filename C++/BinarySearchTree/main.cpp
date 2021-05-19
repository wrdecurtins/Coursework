#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>

using namespace std;

struct TREENODE
{
    int key;
    TREENODE * lchild;
    TREENODE * rchild;
};

//prototypes
void create_tree(TREENODE * & t);
void loadtree(TREENODE * & t);//1
void balance_tree(TREENODE * & t);//2
bool search_tree(TREENODE * t, const int num);//3
int height_tree(TREENODE * t);//4
void print_sorted_tree(TREENODE * t);//5

int rootval_tree(TREENODE * t);//6
void insert_treenode(TREENODE * & t, const int num);//7
void delete_treenode(TREENODE * & t, const int num);//8
void delete_tree(TREENODE * & t);//9

//utility prototypes
void clearscreen(const int cnt);
int count(TREENODE * t);
void fill_array(TREENODE * t, int A[], int & count);
void balancer(TREENODE * & t, int num, int A[], int & fp);
TREENODE * find_min(TREENODE * t);

const int clearvalue = 40;

int main(void)
{
    int input = 1;
    string ch;
    TREENODE * t;
    create_tree(t);

    while ( input != 0 )
    {
        clearscreen(clearvalue);

        cout << " WILLIAM DECURTINS Binary Search Tree Assignment" << endl;
        cout << " ===============================================" << endl;
        cout << " 1: Load Binary Search Tree from 'treedata18.txt'" << endl;
        cout << " 2: Balance Binary Tree" << endl;
        cout << " 3: Look up value in tree" << endl;
        cout << " 4: Height of the tree" << endl;
        cout << " 5: Display sorted list of numbers in tree" << endl;
        cout << " 6: Value of root of tree" << endl;
        cout << " 7: Insert value into tree" << endl;
        cout << " 8: Delete value in tree" << endl;
        cout << " 9: Delete entire tree" << endl;
        cout << " 0: Exit program" << endl;

        cin >> input;
        cout << endl;

        if (input == 1)
        {
            loadtree(t);
            cout << endl << endl;
            cout << "Enter anything to continue";
            cin >>ch;
            cout << endl;
        }
        else if (input == 2)
        {
            balance_tree(t);
            cout << endl << endl;
            cout << "Enter anything to continue";
            cin >>ch;
            cout << endl;
        }
        else if (input == 3)
        {
            clearscreen(2);
            cout << "What number would you like to search for?: ";
            cin >> input;
            cout << endl;

            if (search_tree(t,input))
            {
                cout << "FOUND" << endl << endl;
            }
            else
            {
                cout << "NOT FOUND" << endl << endl;
            }

            cout << "Enter anything to continue";
            cin >>ch;
            cout << endl;
        }
        else if (input == 4)
        {
            clearscreen(2);
            cout << height_tree(t) << endl << endl;
            cout << "Enter anything to continue";
            cin >>ch;
            cout << endl;
        }
        else if (input == 5)
        {
            clearscreen(2);
            print_sorted_tree(t);
            cout << endl << endl;
            cout << "Enter anything to continue";
            cin >>ch;
            cout << endl;
        }
        else if (input == 6)
        {
            cout << rootval_tree(t) << endl << endl;
            cout << "Enter anything to continue";
            cin >>ch;
            cout << endl;
        }
        else if (input == 7)
        {
            cout << "Number to insert: ";
            cin >> input;
            insert_treenode(t,input);
            cout << endl << endl;
            cout << "Enter anything to continue";
            cin >>ch;
            cout << endl;
        }
        else if (input == 8)
        {
            cout << "Number to delete: ";
            cin >> input;
            delete_treenode(t,input);
            cout << endl << endl;
            cout << "Enter anything to continue";
            cin >>ch;
            cout << endl;
        }
        else if (input == 9)
        {
            delete_tree(t);
            cout << endl << endl;
            cout << "Enter anything to continue";
            cin >>ch;
            cout << endl;
        }
    }
    return 0;
}

//functions

void create_tree(TREENODE * & t)
{
    t = NULL;
}

void loadtree(TREENODE * & t)//1
{
    ifstream infile;
    int num;
    infile.open("treedata18.txt");

    if (!infile)
    {
        cerr << "Unable to open the file !!" << endl;
        exit(1);
    }

    infile >> num;
    while(num != -1)
    {
        insert_treenode(t,num);
        infile >> num;
    }
    infile.close();
}

void balance_tree(TREENODE * & t)//2
{
    if (t == NULL) return;
    if (t->lchild == NULL && t->rchild == NULL) return;

    int n = count(t);
    int * A = new int[n];
    int count = 0;
    int fp = 0;

    fill_array(t,A,count);
    delete_tree(t);

    balancer(t,count,A,fp);

    delete[] A;
}

int height_tree(TREENODE * t)//4
{
    if (t == NULL) return -1;

    int right, left;

    left = height_tree(t->lchild);
    right = height_tree(t->rchild);

    if (left > right)
    {
        return left +1;
    }
    else
    {
        return right +1;
    }
}

void print_sorted_tree(TREENODE * t)//5
{
    if (t == NULL) return;
    print_sorted_tree(t->lchild);
    cout << t->key << " ";
    print_sorted_tree(t->rchild);
}

int rootval_tree(TREENODE * t)//6
{
    if (t == NULL)
    {
        cout << "TREE IS EMPTY" << endl;
        return -1;
    }
    else
    {
        return t->key;
    }
}

void delete_treenode(TREENODE * & t, const int num)//8
{
    TREENODE * tmp;

    if (t == NULL) return;

    if (num < t->key)
    {
        delete_treenode(t->lchild, num);
    }
    else if (num > t->key)
    {
        delete_treenode(t->rchild, num);
    }
    else if (t->lchild == NULL)
    {
        tmp = t;
        t = t->rchild;
        delete tmp;
    }
    else if (t->rchild == NULL)
    {
        tmp = t;
        t = t->lchild;
        delete tmp;
    }
    else
    {
        tmp = find_min(t->rchild);
        t->key = tmp->key;
        delete_treenode(t->rchild,t->key);
    }
}

void delete_tree(TREENODE * & t)//9
{
    if (t == NULL) return;

    delete_tree(t->lchild);
    delete_tree(t->rchild);
    delete t;
    t = NULL;
    return;
}

void insert_treenode(TREENODE * & t, const int num)
{
    if (t == NULL)
    {
        t = new TREENODE;
        t->key = num;
        t->lchild = NULL;
        t->rchild = NULL;
    }
    else
    {
        if (t->key != num)
        {
            if (t->key > num)
            {
                insert_treenode(t->lchild,num);
            }
            else if (t->key < num)
            {
                insert_treenode(t->rchild,num);
            }
        }
    }
    return;
}

bool search_tree(TREENODE * t, const int num)
{
    if (t==NULL)
    {
        return false;
    }
    if (t->key == num)
    {
        return true;
    }
    if (t->key != num)
    {
        if (t->key > num)
        {
            return search_tree(t->lchild,num);
        }
        else if (t->key < num)
        {
            return search_tree(t->rchild,num);
        }
    }
}

//utility functions

void clearscreen(const int cnt)
{
    for (int i=0; i<cnt; i++)
        cout << endl;
}

int count(TREENODE * t)
{
    if (t == NULL) return 0;
    return count(t->lchild) + count(t->rchild) + 1;
}

void fill_array(TREENODE * t, int A[], int & count)
{
    if (t == NULL) return;

    fill_array(t->lchild, A, count);
    A[count]= t->key;
    count++;
    fill_array(t->rchild, A, count);
    return;
}

void balancer(TREENODE * & t, int num, int A[], int & fp)
{
    if (num > 0)
    {
        t = new TREENODE;
        t->lchild = NULL;
        t->rchild = NULL;

        balancer(t->lchild,num/2,A,fp);
        t->key = A[fp];
        fp++;
        balancer(t->rchild,(num-1)/2,A,fp);

    }
}

TREENODE * find_min(TREENODE * t)
{
    if (t->lchild == NULL)
    {
        return t;
    }
    else
    {
        return find_min(t->lchild);
    }
}