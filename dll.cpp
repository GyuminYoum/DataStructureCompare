#include <iostream>
#include "dll.hpp"
using namespace std;
    dll::dll()
    {
        head=NULL;
        tail=NULL;
    }
    bool dll::isEmpty()
    {
        if (head==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }   
    }
    //inserting a node with key value1
    void dll::insert(int value1)
    {
        Node* ptr1=NULL;
        //if dll is empty, add the node and assign it head,
        if (head==NULL)
        {
            Node* node1=new Node;
            node1->key=value1;
            node1->prev=NULL;
            node1->next=NULL;
            head=node1;
            tail=node1;
            /*
            cout << "adding " <<  value1 <<" as head " << endl;   */
        }
        //else add a node to the tail
        else
        {

            /*
            ptr1=head;
            while(ptr1->next!=NULL)
            {
                ptr1=ptr1->next;
            }
            */
            ptr1=tail;
            Node* node2=new Node;
            node2->key=value1;
            node2->prev=ptr1;
            node2->next=NULL;
            ptr1->next=node2;
            tail=node2;
            
        }

        /*
        else
        {
            cout << value1 << "already exists in linkedlist" << endl;
        }
        */
        
        
    }
    void dll::deleteElement(int value1)
    {
        Node* node4=search(value1);
        if (node4!=NULL)
        {
            if (node4==head)
            {
                Node * node5=head;
                head=node4->next;
                head->prev=NULL;
                delete node5;
            }
            else if(node4->next==NULL)
            {
                node4->prev->next=NULL;
                Node* node7= new Node;
                node7=node4;
                delete node7;
                
            }
            else
            {
                Node * node6=new Node;
                node6=node4;
                node4->prev->next=node4->next;
                node4->next->prev=node4->prev;
                delete node6;

            }
            
        }
        else
        {
            cout << "value not found " << endl;
        }
        
        
    }
    //search function with integer key

    Node* dll::search(int value1)
    {
        //starting from head, traverse to tail and if value 1 is found then return the node of interest.
        Node* node3=head;
        while (node3!=tail)
        {
            if (node3->key==value1)
            {
                return node3;
            }
            node3=node3->next;
        }
    }
    void dll::display()
    {
        Node * temp1=head;
        if (isEmpty())
        {
            cout << "Empty list. can't print" << endl;
        }
        else
        {
            while(temp1!=NULL)
            {
                if (temp1->next!=NULL)
                {
                    cout << temp1->key << "-->";
                }
                else
                {
                    cout << temp1->key << endl;
                }
                
                
                temp1=temp1->next;
            }
            
        }
        
        

    }
    void dll::showhead()
    {
        if (head==NULL)
        {
            cout << "no head" << endl;
        }
        else
        {
            cout << head->key << endl;
            
        }
        
    }
    Node * dll::gettail()
    {
        if(tail==NULL)
        {
            return NULL;
        }
        else
        {
            return tail;
        }
        
    }
    void dll::destoryall()
    {
        if (isEmpty())
        {
            cout << "Empty list, nothing to wipe. " << endl;
        }
        else
        {
            while(head!=NULL)
            {
                deleteElement(head->key);
                head=head->next;
            }

        }
        

    }
    Node* dll::gethead()
    {
        if(head==NULL)
        {
            return NULL;
        }
        else
        {
            return head;
        }

    }