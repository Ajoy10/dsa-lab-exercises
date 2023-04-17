// Name : Ajoy A
// Register no. : 220970030
// Date : 27/03/2023

#include <iostream>
using namespace std;

struct node{
        int val;
        node* next;
};

class Stack
{
        node* TOS;

        public:
        Stack()
        {
                TOS = NULL;
        }

        void push(int v)
        {
                node* newNode = new node();
                newNode->val = v;

                if(TOS == NULL)
                {
                        TOS = newNode;
                        TOS->next = NULL;
                }else
                {
                        newNode->next = TOS;
                        TOS = newNode;
                }
        }

        int pop()
        {
                if(TOS == NULL)
                {
                        cout<<"Empty";
                        return NULL;
                }
                int val = TOS->val;
                node* temp = TOS;
                TOS = TOS->next;
                delete temp;
                return val;
        }

        void display()
        {
                node* temp = TOS;
                cout<<"Stack: (tos)->";
                while(temp!= NULL)
                {
                        cout<<temp->val<<" ";
                        temp = temp->next;
                }
                cout<<endl;
        }
};

int main()
{
        Stack st;
        int count;

        cout<<"Enter no. of elements to push: ";
        cin>>count;
        cout<<"Enter "<<count<<" elements:";
        for(int i = 0; i < count; i++)
        {
                int e;
                cin>>e;
                st.push(e);
        }
        st.display();
        cout<<"Enter no. of elements to pop: ";
        cin>>count;
        for(int i = 0; i < count; i++)
                cout<<st.pop()<<" popped"<<endl;

        st.display();

}
