#ifndef HASHLINEAR_HPP
#define HASHLINEAR_HPP

#include <string>
#include <iostream>


using namespace std;

struct Node
{
    int key;
    struct Node* next;
};

class Hashlinear
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    Node* *table;
    int numOfcolision =0;
    int searchcollision=0;
    Node* createNode(int key);
public:
    Hashlinear(int bsize);  // Constructor

    // inserts a key into hash table
    void insertItem(int key);

    // hash function to map values to key
    int hashFunction(int key);
    
    void printTable();
    int getNumOfCollision();

    Node* searchItem(int key);
    int getSearchCollision();
    void setNumOfCollision(int value2);
    void setSearchCollision(int value3);

};

#endif
