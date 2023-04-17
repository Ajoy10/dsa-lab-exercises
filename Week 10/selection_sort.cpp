// Name : Ajoy A
// Reg. no : 220970030
// Program : Implementation of selection sort
// Date : 03/04/2023

#include <iostream>
#include "../common/common.cpp"
using namespace std;

void selection_sort(int arr[], int size)
{
        for(int i = 0; i < size; i++)
        {
                int minIndex = i;
                for(int j = i+1; j < size; j++)
                {
                        if(arr[j] < arr[minIndex])
                                minIndex = j;
                }

                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
        }
}

int main()
{
        int count;
        int arr[100];
        input_array(arr, count);
        cout<<"Array before sorting: [ ";
        display_array(arr, count);
        cout<<"]"<<endl;

        selection_sort(arr, count);

        cout<<"Array after sorting: [ ";
        display_array(arr,count);
        cout<<"]"<<endl;
}

