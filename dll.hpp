#ifndef DLL_HPP
#define DLL_HPP
#include <iostream>
using namespace std;

struct Node{
    int key;
    Node * next;
    Node * prev;
};

class dll{
    public:
    dll();
    bool isEmpty();
    void insert(int value1);
    void deleteElement(int value1);
    Node* search(int value1);
    void display();
    void destoryall();
    void showhead();
    Node* gethead();
    Node * gettail();
    

    private:
    Node* head;
    Node* tail;
};


#endif