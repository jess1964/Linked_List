#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>
#include <cstdlib>

using namespace std;
class LinkedList
{
    private:
        struct Node
            {
                int i = NULL;
                Node *next;
            };
            Node *head;
    public:
        LinkedList() // create head of node
        {
            head = NULL;
        }
//////////////////////////////////////////////////////////
        ~LinkedList()
        {
            Node *position = head;
            while(position !=0)
            {
                Node *newly;
                newly = position->next;
                delete position;
                position = newly;
            }
            head = NULL;
            cout << "End Of Program" << endl;
        }
//////////////////////////////////////////////////////////
        void clear()
        {
            Node *position = head;
            while(position !=0)
            {
                Node *newly;
                newly = position->next;
                delete position;
                position = newly;
            }
            head = NULL;
        }
//////////////////////////////////////////////////////////
        int insert(int i)
        {
            Node *nodeptr;
            nodeptr = head;
            Node *newnode;
            newnode = new Node;
            newnode->i = i;
            if(head==NULL)
            {
                newnode->next = NULL;
                head = newnode;
                return 0;
            }
            else
            {
                Node *mid;
                nodeptr = head;
                head = newnode;
                head->next = nodeptr;
            }
            newnode = NULL;
            nodeptr = NULL;
            delete newnode;
            delete nodeptr;
        }
//////////////////////////////////////////////////////////
        int append(int i)
        {
            Node *nodeptr;// check
            Node *newnode;
            newnode = new Node; //check
            newnode->i = i;
            newnode->next = NULL;
            nodeptr = head;
            if(!head)
            {
                head = newnode;
                return 0;
            }
            else
            {
                nodeptr = head;
                while(nodeptr->next)
                    {
                        nodeptr = nodeptr->next;
                    }
                nodeptr->next = newnode;
                nodeptr = NULL;
                newnode = NULL;
                delete nodeptr;
                delete newnode;
                return 0;
            }
            return -1;
        }
///////////////////////////////////////////////////////
        int remove(int i)
        {
         Node *nodeptr;
         Node *old;

         if(!head)
         {
             cout << "List is Empty"<< endl;
             return 0;
         }

         if(head->i == i)
         {
             nodeptr = head->next;
             delete head;
             head = nodeptr;
             return 0;
         }
         else
         {
             nodeptr = head;
             while(nodeptr != NULL && nodeptr->i != i)
             {
                 old = nodeptr;
                 nodeptr = nodeptr->next;
             }
             if(nodeptr)
             {
                 old->next = nodeptr->next;
                 delete nodeptr;
                 return 0;
             }

         }
         return -1;

        }
//////////////////////////////////////////////////////////
        bool isFull() const
        {
            if(head == NULL)
            {
                return 0;
            }
            if(head != NULL)
            {
                return 1;
            }
        }
//////////////////////////////////////////////////////////
        bool isEmpty() const
        {
            if(head == NULL)
            {
                return 1;
            }
            if(head != NULL)
            {
                return 0;
            }
        }
//////////////////////////////////////////////////WORKING
        int getLength() const
        {
            Node *nodeptr; // navigator
            int counter = 0;
            if(head == NULL)
            {
                return counter;
            }
            nodeptr = head;
            while(nodeptr != NULL)
            {
                counter++;
                nodeptr= nodeptr->next;
            }
            delete nodeptr;
            return counter;
        }
////////////////////////////////WORKING/////////////////////
        bool find(int i) const
        {

            Node *nodeptr;
            nodeptr = head;
            if(head->i == i)
            {
                return 1;
            }
            while(nodeptr->next)
            {
                if(nodeptr->i == i)
                {
                    return 1;
                }
                nodeptr = nodeptr->next;
            }
            return 0;
        }
////////////////////////////////////////////////////
        void print() const
        {
            Node *nodeptr;
            nodeptr = head;
            int counter =0;
            while(nodeptr != NULL)
            {
                cout << nodeptr->i <<" ";
                nodeptr = nodeptr->next;
            }
            cout << endl;
            nodeptr = NULL;
            delete nodeptr;
        }
};

#endif // LINKEDLIST_H_INCLUDED
