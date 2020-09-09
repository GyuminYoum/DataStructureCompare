#include "hashchain.hpp"
#include <iostream>
using namespace std;
Node* Hashchain::createNode(int key1)
{
    Node* Node1=new Node;
    Node1->key=key1;
    Node1->next=NULL;
    return Node1;
}
    Hashchain::Hashchain(int bsize)
    {
        tableSize=bsize;
        table=new Node*[tableSize];
        for (int i=0; i<tableSize; i++)
        {
            table[i]==NULL;
        }
        numOfcolision=0;
        searchcollision=0;
    }  // Constructor

    // inserts a key into hash table
    void Hashchain::insertItem(int key1)
    {
        int hash_value1=hashFunction(key1);
        Node* ptr1=NULL;
        /*
        return hash_value1;
        */
       /*
       return key1;
       */
        //if the index that applies to key1 is empty,
        if (table[hash_value1]==NULL)
        {
            //make node,
            table[hash_value1]=createNode(key1);
            /*
            cout << key1 << "added to empty" << endl;
            */
        }
        //if not,
        else
        {
            //collision happened.
            numOfcolision++;
            //assign pointer to the location in hash table,
            ptr1=table[hash_value1];
            //if the pointer doesn't have next, make node and assign it.
            if (ptr1->next==NULL)
            {
                ptr1->next=createNode(key1);
            }
            else
            {
                //otherwise iterate through to the end of linked list and add the element there.
                while(ptr1->next!=NULL)
                {
                    ptr1=ptr1->next;
                }
                if (ptr1->next==NULL)
                {
                    /*
                    cout << key1 << "added to existing chain." << endl;
                    */
                    ptr1->next=createNode(key1);
                }
                
            }
        }
    }
    // hash function to map values to key
    int Hashchain::hashFunction(int key)
    {
        int hashvalue2=0;
        hashvalue2=key%tableSize;
        return hashvalue2;
    }
    
    void Hashchain::printTable()
    {
        int count3=0;
        for (int i=0; i<tableSize; i++)
        {
            Node* temp2=table[i];
            count3=0;
            if (table[i]!=NULL)
            {
                if(table[i]->next==NULL)
                {
                    cout << i << ": " << temp2->key << " " << endl;
                }
                else
                {
                    cout << i << ": ";
                    while(temp2->next!=NULL)
                    {
                        cout <<  temp2->key << "->";
                        temp2=temp2->next;
                    }
                    cout << temp2->key << endl;

                    
                }
                
            }
            
        }
    }
    void Hashchain::setNumOfCollision(int value2)
    {
        numOfcolision=value2;
    }
    void Hashchain::setSearchCollision(int value3)
    {
        searchcollision=value3;
    }
    int Hashchain::getNumOfCollision()
    {
        return numOfcolision;
    }
    int Hashchain::getSearchCollision()
    {
        return searchcollision;
    }
    int Hashchain::getchain(int key2)
    {
        int hash_value=hashFunction(key2);
        int count1=0;
        Node * temp1=NULL;
        for (int i=0; i<tableSize; i++)
        {
            temp1=table[i];
            if(table[i]!=NULL)
            {
                if(table[i]->next!=NULL)
                {
                    while(temp1!=NULL)
                    {
                        temp1=temp1->next;
                        count1++;
                    }
                    return count1;

                }
            }
        }

    }

    //searching function based on integer value.
    Node* Hashchain::searchItem(int key1)
    {
        int hash_value=hashFunction(key1);
        Node* temp2=NULL;
        bool found=false;
        temp2=table[hash_value];
        //if the hash table at that index is empty, return nothing
        if(table[hash_value]==NULL)
        {
            return NULL;
        }
        //else if hash table already has a node at the index and that node is the one of interest,
        //return,
        else if (table[hash_value]->key==key1)
        {
            return table[hash_value];
        }
        //if none of the above cases apply,
        else if(table[hash_value]->key!=key1)
        {
            //case of search collision
            searchcollision++;
            temp2=table[hash_value];
            //iterate through the end of linked list at the hash table index,
            while(temp2->next!=NULL)
            {
                //during the iteration, if node of interest is found, mark found and return.
                if(temp2->key==key1)
                {
                    found=true;
                    return temp2;
                }
                temp2=temp2->next;
            }
            //At the end of the linked list, if the last node is the one of interest, 
            //mark true and return.
            if(temp2->next==NULL)
            {
                if(temp2->key==key1)
                {
                    found=true;
                    return temp2;
                }
            }
            //if its not in the linked list at the table index, return NULL;
            if(found==false)
            {
                return NULL;
            }
        }

    
        

        
        
        
            
        

    }