// Name : Ajoy A
// Register no. : 220970030
// Date : 20/02/2023
// Program title : Implementation of generic stack class

#include<iostream>
#define STACK_MAX 100
using namespace std;

template<typename T>
class Stack
{
                          private:
                                T arr[STACK_MAX];
                                int tos;
                          public:
                                int size;

                                Stack(int size){
                                        this->size = size;
                                        this->tos = -1;
                                }

                                bool isEmpty()
                                {
                                        return tos < 0;
                                }

                                bool isFull()
                                {
                                        return tos == size - 1;
                                }



                                void push(T val){
                                        if(isFull())
                                        {
                                                cout<<"Stack overflow!"<<endl;
                                                return;
                                        }

                                        arr[++tos] = val;
                                }

                                T pop()
                                {
                                        if(isEmpty()){
                                                cout<<"Stack underflow!"<<endl;
                                                return 0;
                                        }

                                        return arr[tos--];
                                }

                                T peek()
                                {
                                        return arr[tos];
                                }

                                int count()
                                {
                                        return tos + 1;
                                }

                                void display()
                                {
                                        cout<<"Stack: "<<endl;
                                        for(int i = tos; i >= 0; i--)
                                        {
                                                cout<<arr[i]<<endl;
                                        }
                                        cout<<endl;
                                }
};