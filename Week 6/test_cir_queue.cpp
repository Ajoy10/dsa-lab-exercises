#include <iostream>
#include "my_circular_queue.h"
using namespace std;

void EnqueueFromUser(CircularQueue<int>& q)
{

        cout<<"Enter no. of elements to enqueue: ";
        int el_size;
        cin>>el_size;
        cout<<"Enter "<<el_size<<" elements: ";
        for(int i = 0; i < el_size; i++)
        {
                int ele;
                cin>>ele;
                q.Enqueue(ele);
        }
}

void DequeueFromUser(CircularQueue<int>& q)
{

        int el_size;
        cout<<"Enter no. of elements to dequeue: ";
        cin>>el_size;
        for(int i = 0; i < el_size; i++)
        {
                cout<<q.Dequeue()<<" dequeued"<<endl;
        }
        cout<<endl;
}

int main()
{
        cout<<"Enter size of queue: ";
        int size;
        cin>>size;
        CircularQueue<int> q(size);

        try{
                EnqueueFromUser(q);

                q.Display();

                DequeueFromUser(q);

                q.Display();

                EnqueueFromUser(q);

                q.Display();

                DequeueFromUser(q);

                q.Display();

        }catch(CircularQueue<int>::QueueException exc)
        {
                cout<<"Queue exception occured! : "<<exc.message<<endl;
        }
}