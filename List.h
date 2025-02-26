#include <bits/stdc++.h>
#include "User.h"

using namespace std;

class Node {

    public:

        Contact contact;
        Node *next;

        Node(Contact contact) {
            this->contact = contact;
            next = NULL;
        }


};


class List {

    private:
        Node *head;


    public:

        List() {
            head = NULL;
        }

        bool isEmpty() {

            if(head==NULL)
                return true;
            return false;
        }


        void insertAtFirst(Contact contact) {

            Node *newNode = new Node(contact);

            if(head==NULL)
                head = newNode;
            
            else {
                newNode->next = head;
                head = newNode;
            }
            
        }


        void insertAt(Contact contact, int value) {
            
            int currentIndex = 1;
            Node* currentNode = head;

            while(currentNode && currentIndex!=value) {
                currentNode = currentNode->next;
                currentIndex++;
            }

            if(currentNode) {
                currentNode->contact = contact;
            }

        }


        Contact findNodeContact_Index(int value) {

            int currentIndex = 1;
            Node* currentNode = head;

            while(currentNode && currentIndex!=value) {
                currentNode = currentNode->next;
                currentIndex++;
            }

            if(currentNode)
                return currentNode->contact;

            return Contact();

        }


        Contact findNodeContact(string value) {

            Node* currentNode = head;

            while(currentNode && (currentNode->contact.getFirstName()!=value && currentNode->contact.getLastName()!=value && currentNode->contact.getViewName()!=value && currentNode->contact.getNumber()!=value )) {
                currentNode = currentNode->next;
            }

            if(currentNode) {
                return currentNode->contact;
            }

            return Contact();

        }


        Node *findNode(int value) {

            int currentIndex = 1;
            Node* currentNode = head;

            while(currentNode && currentIndex!=value) {
                currentNode = currentNode->next;
                currentIndex++;
            }

            if(currentNode)
                return currentNode;

            return NULL;

        }
        
        


        void sort() {               // Bubble sort

            if(head==NULL) {
                return;
            }


            Node *iNode = head;
            Node *jNode = head;

            while(iNode) {

                jNode = head;


                while(jNode!=NULL && jNode->next!=NULL) {

                    if(jNode->contact.getViewName() > jNode->next->contact.getViewName()) {
                        swapNode(jNode,jNode->next);
                        iNode = head;                   // cz head changed after swap
                    }
                    else
                        jNode = jNode->next;
                }

                iNode = iNode->next;
            }


        }


        void swapNode(Node *a, Node *b) {       // Only for two(a,b) alongside Node

            Node *tempHead = head;
            Node *aPrev = NULL;
            Node *bNext = b->next;

            if(a!=head) {
                while(tempHead!=a) {
                    aPrev = tempHead;
                    tempHead = tempHead->next;
                }
            }


            if(a==head) {
                head = b;
                b->next = a;
                a->next = bNext;
            }

            else if(b->next==NULL) {
                aPrev->next = b;
                b->next = a;
                a->next = NULL;
            }

            else {
                aPrev->next = b;
                b->next = a;
                a->next = bNext;
            }

        }








        void deleteDuplicate() {


            if(head==NULL) {
                return;
            }


            Node *iNode = head;
            Node *jNode = NULL;
            Node *temp;
        

            while(iNode && iNode->next) {

                jNode = iNode;

                while(jNode->next) {

                    if(iNode->contact.getViewName()==jNode->next->contact.getViewName()) {
                        temp = jNode->next;
                        jNode->next = jNode->next->next;
                        delete temp;
                    }

                    else{
                        jNode = jNode->next;
                    }
                }

                iNode = iNode->next;
            }

            cout << "\n\t Duplicate Contacts removed" << endl;

        }




        void deleteNode(int value) {

            int currentIndex = 1;
            Node* prevNode = NULL;
            Node* currentNode = head;

            while(currentNode && currentIndex!=value) {
                prevNode = currentNode;
                currentNode = currentNode->next;
                currentIndex++;
            }

            if(currentNode) {

                if(prevNode) {
                    prevNode->next = currentNode->next;
                    delete currentNode;
                    cout << "\n\t Serial ["<< value << "] Deleted successfully" << endl;
                }

                else {
                    head = currentNode->next;
                    delete currentNode;
                    cout << "\n\t Serial ["<< value << "] Deleted successfully" << endl;                    
                }
            }

            else {
                cout << "\n\t There is no such serial [" << value << "]" << endl;
            }

        }  



        void deleteNode_Node(Node *deleteNode, int value) {

            Node* prevNode = NULL;
            Node* currentNode = head;

            while(currentNode && deleteNode!=currentNode) {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }

            if(currentNode) {

                if(prevNode) {
                    prevNode->next = currentNode->next;
                    delete currentNode;
                    cout << "\n\t Serial ["<< value << "] Deleted successfully" << endl;
                }

                else {
                    head = currentNode->next;
                    delete currentNode;
                    cout << "\n\t Serial ["<< value << "] Deleted successfully" << endl;                    
                }
            }

            else {
                cout << "\n\t There is no such serial [" << value << "]" << endl;
            }

        } 



        void deleteNode_Contact(Contact contact) {

            Node* prevNode = NULL;
            Node* currentNode = head;

            while(currentNode && currentNode->contact.getViewName() != contact.getViewName()) {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }

            if(currentNode) {

                if(prevNode) {
                    prevNode->next = currentNode->next;
                    delete currentNode;
                    cout << "\n\t Contact Deleted successfully" << endl;
                }

                else {
                    head = currentNode->next;
                    delete currentNode;
                    cout << "\n\t Contact Deleted successfully" << endl;                    
                }
            }

            else {
                cout << "\n\t There is no such Contact" << endl;
            }

        }





        void printList() {

            Node* tempHead = head;

            if(head==NULL) {
                cout << "\n\t List is EMPTY\n" << endl;
                return;
            }

            int i = 1;
            cout << "\nList : \n";

            while(tempHead!=NULL) {
                cout << "\n\t [" << i++ << "]\t"; 
                tempHead->contact.displayList();
                tempHead = tempHead->next; 
            }

            cout << endl;
        }

};
