#include<iostream>
using namespace std;
struct node{
        int val;
        node* next;
};

class Queue
{
        node* HEAD;
        public:
        Queue()
        {
                HEAD = NULL;
        }

        void enqueue(int v)
        {
                node* newNode = new node;
                newNode->val = v;
                newNode->next = NULL;
                if(HEAD == NULL)
                {
                        HEAD = newNode;
                }else{
                        node* temp = HEAD;
                        while(temp->next != NULL)
                                temp = temp->next;
                        temp->next = newNode;
                }
        }

        int dequeue()
        {
                if(HEAD == NULL)
                {
                        cout<<"Empty"<<endl;
                        return NULL;
                }

                int val = HEAD->val;
                node* temp = HEAD;
                HEAD = HEAD->next;
                delete temp;
                return val;
        }

        void display()
        {
                if(HEAD == NULL)
                {
                        cout<<"<empty>"<<endl;
                }else{
                        cout<<"Queue: front-> ";
                        node* temp = HEAD;
                        while(temp!=NULL)
                        {
                                cout<<temp->val<<" ";
                                temp = temp->next;
                        }

                        cout<<" <-rear"<<endl;
                }
        }

};

int main()
{
        Queue q;
        int count;
        cout<<"Enter no. of items to add: ";
        cin>>count;
        cout<<"Enter "<<count<<" items: ";
        for(int i = 0; i < count; i++)
        {
                int val;
                cin>>val;
                q.enqueue(val);
        }

        q.display();

        cout<<"Enter no. of items to remove: ";
        cin>>count;
        for(int i = 0; i < count; i++)
        {
                cout<<q.dequeue()<<" dequeued"<<endl;
        }

        q.display();
}
