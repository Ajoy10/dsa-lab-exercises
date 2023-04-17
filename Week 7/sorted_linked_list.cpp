#include <iostream>
using namespace std;

struct node{
        int data;
        struct node* next;
};

void insert(struct node * &HEAD, int val)
{
        if(HEAD == NULL)
        {
                HEAD = (node *)malloc(sizeof(node));
                HEAD->next = NULL;
                HEAD->data = val;

        }else if(HEAD->data > val)
        {
                node* newNode = (node*) malloc(sizeof(node));
                newNode->data = val;
                node* temp = HEAD;
                HEAD = newNode;
                newNode->next = temp;
        }else{
                struct node * temp = HEAD;
                struct node *newNode = (node *)malloc(sizeof(node));
                newNode->data = val;
                while(temp!= NULL)
                {
                        if(temp->next == NULL)
                        {
                                temp->next = newNode;
                                newNode->next = NULL;
                                break;
                        }
                        else if(temp->next->data > val) // If next node has higher value then add between current and next
                        {
                                newNode->next = temp->next;
                                temp->next = newNode;
                                break;

                        }

                        temp = temp->next;

                }
        }
}

void display(struct node * HEAD)
{
        struct node * temp = HEAD;
        cout<<"Linked list: ";
        while(temp!=NULL)
        {
                cout<<" "<<temp->data;
                temp = temp->next;
        }
}

void delete_node(struct node * &HEAD, int target)
{
        bool found = false;
        struct node * temp = HEAD;
        if(HEAD!=NULL && HEAD->data == target)
        {
                found = true;
                node* T = HEAD;
                HEAD = HEAD->next;
                delete T;
                return;
        }

        while(temp != NULL)
        {
                if(temp->next->data == target)
                {
                        found = true;
                        struct node* T = temp->next;
                        temp->next = T->next;
                        delete T;
                        break;
                }else if(temp->next->data > target)
                {
                        break;
                }
                else{
                        temp = temp->next;
                }
        }

        if(!found)
        {
                cout<<"Could not find the target!"<<endl;
        }



}



int main()
{
        struct node * HEAD = NULL;


        cout<<"Enter 5 elements: ";
        for(int i = 0; i < 5; i++)
        {
                int v;
                cin>>v;
                insert(HEAD, v);
        }

        display(HEAD);
        cout<<endl;

        cout<<"Element to delete: ";
        int target;
        cin>>target;

        delete_node(HEAD, target);
        display(HEAD);
        cout<<endl;
}
