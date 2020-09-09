#include "hashquad.hpp"
#include <iostream>
#include <cmath>
using namespace std;

    Node* Hashquad::createNode(int key1)
    {
        Node* Node1=new Node;
        Node1->key=key1;
        return Node1;

    }
    Hashquad::Hashquad(int bsize)
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
    void Hashquad::insertItem(int key1)
    {
        int temp1=0;
        int newindex=0;
        int count1=0;
        int temp2=0;
        Node* ptr1=NULL;
        //calculate index
        temp1=hashFunction(key1);

        /*
        return temp1;
        */
       /*
            if (table[temp1]==NULL)
            {
                table[temp1]=createNode(key1); 
            }
            else 
            {
                numOfcolision++;
                temp2=temp1;
                while (table[temp1%tableSize]!=NULL)
                {
                    temp1=(temp2+(count1*count1));
                    count1++;
                }
                if(table[temp1%tableSize]==NULL)
                {
                    table[temp1%tableSize]=createNode(key1);
                }
            }
        */       
       //if hashtable at index is empty, add it there.
        if (table[temp1]==NULL)
        {
            table[temp1]=createNode(key1);
            /*
            cout << key1 << " added to empty bucket" << endl;
            */
        
        }
        //else, its a collision
        else 
        {
            numOfcolision++;
            count1=0;
            //while loop to find next empty slot in hash table using quad probing.
            while (table[temp2]!=NULL)
            {
                temp2=(temp1+(count1*count1))%tableSize;
                count1++;
                //if the iteration went for more than 10000times, assume hash tables full.
                if (count1>=10000)
                {
                    cout << "hash table full" << endl;
                    break;
                }
            }
            //if index of hashtable that is empty is found, exit the while loop and make node there.
            if(table[temp2]==NULL)
            {
                table[temp2]=createNode(key1);
                /*
                return temp2;
                */
                
                /*
                cout << key1 << " added to pre-existing bucket" << endl;
                */
            
            }
            
        }
        
       
       
    }

    // hash function to map values to key
    int Hashquad::hashFunction(int key)
    {
        int hashvalue2=0;
        hashvalue2=key%tableSize;
        return hashvalue2;
    }

    void Hashquad::printTable()
    {
        for(int i=0; i<tableSize; i++)
        {
            if (table[i]!=NULL)
            {
                cout << i << ": " << table[i]->key << " ";

            }
        }
    }
    void Hashquad::setNumOfCollision(int value2)
    {
        numOfcolision=value2;
    }
    void Hashquad::setSearchCollision(int value3)
    {
        searchcollision=value3;
    }
    int Hashquad::getNumOfCollision()
    {
        return numOfcolision;

    }
    int Hashquad::getSearchCollision()
    {
        return searchcollision;
    }

//searching function
    Node* Hashquad::searchItem(int key1)
    {
        //calculate index,
        int hashvalue1=hashFunction(key1);
        int temphash=0;
        int count1=0;
        bool found=false;
        //if table at the index is empty, just return NULL ptr.
        if(table[hashvalue1]==NULL)
        {
            return NULL;
        }
        //if there is something at the index,
        else
        {
            //if the pre-occupying node doesn't have the key of interest,
            //its a collision.
            if (table[hashvalue1]->key!=key1)
            {
                searchcollision++;
                //until you find empty space in hash table which would indicate the end of the iteration, increase the index in quadratic fashion
                //if node with key of interest is found, then return it.
                while(table[temphash]!=NULL)
                {
                    if(table[hashvalue1]->key==key1)
                    {
                        found=true;
                        return table[hashvalue1];
                    }
                    temphash=(hashvalue1+(count1*count1))%tableSize;
                    count1++;
                }

            }
            //if it is the node of interest, return it
            else
            {
                found=true;
                return table[hashvalue1];
            }
            //if bool variable found stays false, it means the interested node is not present.
            //return NULL
            if (found==false)
            {
                return NULL;
            }
        }
    

            
        
        
        
        /*
        if (table[hashvalue1]->key=key2)
        {
            return 0;
        }
        else
        {
            temphash=hashvalue1;
            while(table[hashvalue1]->key!=key2)
            {
                hashvalue1=(temphash+(count1*count1))%tableSize;
                count1++;
            }
            if(table[hashvalue1]->key==key2)
            {
                return count1;
            }
            return count1;

        }
        */


    }