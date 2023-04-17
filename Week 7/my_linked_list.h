// Name : Ajoy
// Register no. : 220970030
// Program : Implementation of singly linked list
// Date : 20-03-2023

#include <iostream>
using namespace std;

struct node{
        int data;
        node* next;
};

void insert_end(node* &HEAD, int val)
{
        if(HEAD == NULL)
        {
                HEAD = (node *)malloc(sizeof(node));
                HEAD->next = NULL;
                HEAD->data = val;
                return;
        }else
        {
                node* temp = HEAD;
                while(temp->next != NULL)
                {
                        temp = temp->next;
                }
                node* newNode = (node *)malloc(sizeof(node));
                newNode->data = val;
                newNode->next = NULL;
                temp->next = newNode;
        }
}

void display(node* HEAD)
{
        node* temp = HEAD;
        cout<<"Linked List: ";
        while(temp != NULL)
        {
                cout<<" "<<temp->data;
                temp = temp->next;
        }
        cout<<endl;
}
