#ifndef HASHCHAIN_HPP
#define HASHCHAIN_HPP

#include <string>
#include <iostream>


using namespace std;

struct Node
{
    int key;
    struct Node* next;
};

class Hashchain
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    Node* *table;
    int numOfcolision =0;
    int searchcollision=0;
    
    Node* createNode(int key);
public:
    Hashchain(int bsize);  // Constructor

    // inserts a key into hash table
    void insertItem(int key);

    // hash function to map values to key
    int hashFunction(int key);
    int getchain(int key2);
    void printTable();
    int getdupe();
    int getNumOfCollision();
    int getSearchCollision();
    void setNumOfCollision(int value2);
    void setSearchCollision(int value3);
    int gethop(int key2);

    Node* searchItem(int key);
};

#endif
