#include <iostream>
#include "my_queue.h"
using namespace std;

int main()
{
        cout<<"Enter size of queue: ";
        int size;
        cin>>size;
        Queue<int> q(size);

        cout<<"Enter no. of elements to enqueue: ";
        int el_size;
        cin>>el_size;
        cout<<"Enter "<<el_size<<" elements: ";
        try{
                for(int i = 0; i < el_size; i++)
                {
                        int ele;
                        cin>>ele;
                        q.Enqueue(ele);
                }

                q.Display();

                cout<<"Enter no. of elements to dequeue: ";
                cin>>el_size;
                for(int i = 0; i < el_size; i++)
                {
                        cout<<q.Dequeue()<<" dequeued"<<endl;
                }
                cout<<endl;

                q.Display();
        }catch(Queue<int>::QueueException exc)
        {
                cout<<"Queue exception occured! : "<<exc.message<<endl;
        }
}