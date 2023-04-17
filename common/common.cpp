// Name : Ajoy A
// Reg. no : 220970030
// Program : Some common utility functions
// Date : 03/04/2023

#include <iostream>

template<class T>
void display_array(T arr[], int size)
{
        for(int i = 0; i < size; i++)
        {
                std::cout<<arr[i]<<" ";
        }
}

template<class T>
void input_array(T arr[], int &count)
{
        std::cout<<"Enter the size of the array: ";
        std::cin>>count;
        std::cout<<"Enter "<<count<<" elements:";
        for(int i = 0; i < count; i++)
                std::cin>>arr[i];
}
