// Name : Ajoy A
// Register no. : 220970030
// Program ; Implementation of Bubble sort
// Date : 17/04/2023

#include <iostream>
#include "../common/common.cpp"

#define MAX 50
using namespace std;

void bubble_sort(int arr[], int count)
{
        for(int i = 0; i < count - 1; i++)
        {
                for(int j = 0; j < count - 1 - i; j++)
                {
                        if(arr[j] > arr[j+1])
                        {
                                // Swap arr[j] and arr[j+1]
                                int temp = arr[j+1];
                                arr[j+1] = arr[j];
                                arr[j] = temp;
                        }
                }
        }
}

int main()
{
        int arr[MAX];
        int count;
        input_array(arr, count);
        cout<<"Array before sorting: [ ";
        display_array(arr,count);
        cout<<"]"<<endl;
        bubble_sort(arr,count);
        cout<<"Array after sorting: [ ";
        display_array(arr,count);
        cout<<"]"<<endl;
}
