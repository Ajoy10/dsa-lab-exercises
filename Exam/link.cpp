#include <iostream>
using namespace std;

struct node{
        int data;
        node* next;
};

class LinkList
{
        node* HEAD;
        public:
        LinkList()
        {
                HEAD = NULL;
        }

        void insert(int val)
        {
                node* newNode = new node;
                newNode->data = val;
                newNode->next = NULL;
                if(HEAD == NULL)
                {
                        HEAD = newNode;
                }else
                {
                        node* temp = HEAD;
                        while(temp->next != NULL)
                                temp = temp->next;

                        temp->next = newNode;
                }
        }

        void delete_node(int target){
                if(HEAD == NULL)
                {
                        cout<<"Empty list";
                        return;
                }else if(HEAD->data == target)
                {
                        //cout<<"Deleting "<<HEAD->data<<" next= "<<HEAD->next<<endl;
                        node* t = HEAD;
                        HEAD = t->next;
                        //delete t;
                        return;
                }
                else{
                        node* temp = HEAD;
                        while(temp->next!=NULL)
                        {
                                if(temp->next->data == target)
                                {
                                        node* t = temp->next;
                                        temp->next = t->next;
                                //      cout<<"Deleting "<<t->data<<endl;
                                        delete t;
                                        return;
                                }

                                temp = temp->next;
                        }
                        cout<<"Could not find the target"<<endl;
                }
        }

        void delete_negetive()
        {
                node* temp = HEAD;
                while(temp->next != NULL)
                {
                        //cout<<"Checking "<<temp->data<<endl;
                        if(temp->data < 0)
                        {
                                node* t = temp->next;
                                delete_node(temp->data);
                                delete_negetive();
                                return;
                        }
                        temp = temp->next;
                }

                if(temp != NULL && temp->data < 0)
                {
                        delete_node(temp->data);
                }

        }

        void display()
        {
        //      cout<<"HEAD: "<<HEAD->data<<endl;
                cout<<"Linked list: ";
                node* temp = HEAD;
                if(temp == NULL)
                {
                        cout<<"<empty>"<<endl;
                        return;
                }

                while(temp != NULL)
                {
                        cout<<temp->data<<" ";
                        temp = temp->next;
                }
                cout<<endl;
        }
};


int main()
{
        int count;
        LinkList list;
        cout<<"Enter no. of elements: ";
        cin>>count;
        cout<<"Enter "<<count<<" elements: ";
        for(int i = 0; i < count; i++)
        {
                int ele;
                cin>>ele;
                list.insert(ele);
        }

        cout<<"Before deletion: ";
        list.display();

        list.delete_negetive();
        //list.delete_node(-20);
        //list.delete_node(-20);
        //list.delete_node(-20);
        cout<<"After deletion: ";
        list.display();
}
