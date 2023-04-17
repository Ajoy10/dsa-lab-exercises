// Name : Ajoy A
// Register no. : 220970030
// Program : Generic circular queue implementation using array
// Date : 13/03/2023

#include <iostream>
using namespace std;
#define MAX_Q 50

template <typename T>
class CircularQueue
{

        int size;
        T arr[MAX_Q];
        int front, rear;
        public:
                class QueueException{
                        public:
                                string message;
                                QueueException(string msg){
                                        message = msg;
                                }
                };

                CircularQueue(int size)
                {
                        front = rear = -1;
                        this->size = size;
                }

                bool isEmpty()
                {
                        if(front == -1)
                        {
                                return true;
                        }else{
                                return false;
                        }
                }

                bool isFull()
                {
                        if(front == rear + 1 || (front == 0 && rear == size-1))
                        {
                                return true;
                        }else{
                                return false;
                        }
                }

                void Enqueue(T val)
                {
                        if(isFull())
                        {
                                throw QueueException("Queue overflow!");
                        }else
                        {
                                if(front == -1)
                                {
                                        front = 0;
                                }
                                rear = (rear + 1) % size;
                                arr[rear] = val;
                        }
                }

                T Dequeue()
                {
                        if(isEmpty())
                        {
                                throw QueueException("Queue underflow!");
                        }
                        else
                        {
                                T ele = arr[front];
                                if(rear == front) // If this was the last element reinitialize the queue
                                        rear = front = -1;
                                else
                                        front = (front + 1)%size;

                                return ele;
                        }
                }

                void Display()
                {
                        cout<<"front = "<<front<<" rear = "<<rear<<endl;
                        cout<<"Queue: ";

                        if(isEmpty()){
                                cout<<"<empty>"<<endl;
                                return;
                        }else{
                                for(int i = front; i !=rear ; i = (i+1)%size)
                                {
                                        cout<<arr[i]<<" ";
                                }
                                cout<<arr[rear]<<endl;
                        }
                }

};