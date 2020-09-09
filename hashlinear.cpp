#include "hashlinear.hpp"
#include <iostream>
using namespace std;

    Node* Hashlinear::createNode(int key1)
    {
        Node* Node1=new Node;
        Node1->key=key1;
        return Node1;

    }
    Hashlinear::Hashlinear(int bsize)
    {
        tableSize=bsize;
        table=new Node* [tableSize];
        for (int i=0; i<tableSize; i++)
        {
            table[i]=NULL;
        }
        searchcollision=0;
        numOfcolision=0;

    } // Constructor

    // inserts a key into hash table
    void Hashlinear::insertItem(int key1)
    {
        int temp1=0;
        int temp4=0;
        int temp3=0;
        int indexadded=0;
        int count=0;
        Node* temp2=NULL;
        //calculate index
        temp1=hashFunction(key1);
        /*
        return temp1;
        */
    
        
        //if index of the hashtables empty, add it
        if (table[temp1]==NULL)
        {
            table[temp1]=createNode(key1); 
            
            /*
            cout << "adding " << key1 << "to empty bucket" << endl;
            */

        }
        //otherwise, its a collision.
        else
        {
            temp3=temp1;
            numOfcolision++;
            //Until an empty space in hashtable is located, iterate index by 1.
            while (table[temp3]!=NULL)
            {
                temp3=temp1+indexadded;
                temp3=temp3%tableSize;
                indexadded++;
                //if iteration happened more than 10000 times, assume hashtables full.
                if (indexadded>=40009)
                {
                    cout << "hashtable full" << endl;
                    break;
                }
            }
            //when we get to the empty hashtable index, add node.
            if(table[temp3]==NULL)
            {
                table[temp3]=createNode(key1);
                
                /*
                return temp1;
                */
                
                /*
                cout << "adding " << key1 << " to pre-existing bucket" << endl;
                */
               
            }  
        }
        

    }

    // hash function to map values to key
    int Hashlinear::hashFunction(int key)
    {
        int hashvalue2=0;
        hashvalue2=key%tableSize;
        return hashvalue2;
    }

    void Hashlinear::printTable()
    {
        for(int i=0; i<tableSize; i++)
        {
            if (table[i]!=NULL)
            {
                cout << i << ": " << table[i]->key << " ";

            }
        }
    }
    void Hashlinear::setNumOfCollision(int value2)
    {
        numOfcolision=value2;
    }
    void Hashlinear::setSearchCollision(int value3)
    {
        searchcollision=value3;
    }
    int Hashlinear::getNumOfCollision()
    {
        return numOfcolision;

    }
    int Hashlinear::getSearchCollision()
    {
        return searchcollision;
    }

    //function to search key1
    Node* Hashlinear::searchItem(int key1)
    {
        bool found=false;
        //calculate index,
        int hashvalue1=hashFunction(key1);
        int hashvalue2=0;
        int count=0;
        hashvalue2=hashvalue1;
        //check if theres a node thats already occupying the hashtable at the index.
        //if there isn't return NULL
        if (table[hashvalue2]==NULL)
        {
            found=false;
            return NULL;
        }
        //otherwise
        //
        else
        {
            //if the node's key at the index isnt they key we are interested in, then its a collision.
            if(table[hashvalue2]->key!=key1)
            {
                searchcollision++;
                //Until you find an empty spot in the hashtable, iterate the index by 1 each time.
                //search ends if you find an empty spot or they interested key value.
                while(table[hashvalue2]!=NULL)
                {
                    if (table[hashvalue2]->key==key1)
                    {
                        found=true;
                        return table[hashvalue1];
                    }
                    hashvalue2=hashvalue1+count;
                    count++;
                }
            }
            //if the node's key is of interest,
            //return
            else
            {
                found=true;
                return table[hashvalue2];
            }
            
            //if the bool variable didn't get updated, meaning there was no element that meet the search criteria,
            //return NULL
            if (found==false)
            {
                return NULL;
            }
        }
        
    }