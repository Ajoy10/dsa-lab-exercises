// Name : Ajoy A
// Register no. : 220970030
// Program : Generic queue implementation using array
// Date : 13/03/2023

#include <iostream>
using namespace std;
#define MAX_Q 50

template <typename T>
class Queue
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

                Queue(int size)
                {
                        front = rear = -1;
                        this->size = size;
                }

                bool isEmpty()
                {
                        if(front == -1 || front > rear)
                        {
                                return true;
                        }else{
                                return false;
                        }
                }

                bool isFull()
                {
                        if(rear==size-1)
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
                                rear++;
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
                                return arr[front++];
                        }
                }

                void Display()
                {
                        cout<<"Queue: ";
                        for(int i = front; i <= rear; i++)
                        {
                                cout<<arr[i]<<" ";
                        }
                        cout<<endl;

                        cout<<"front = "<<front<<" rear = "<<rear<<endl;
                }

};