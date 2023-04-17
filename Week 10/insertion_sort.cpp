// Name : Ajoy A
// Register no. : 220970030
// Program ; Implementation of Insertion sort
// Date : 03/04/2023

#include <iostream>
#include "../common/common.cpp"

#define MAX 50
using namespace std;

void insertion_sort(int arr[], int count)
{
        for(int i = 0; i < count; i++)
        {
                int hold = arr[i];
                int j = i - 1;
                while(j >= 0 && arr[j] > hold)
                {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = hold;
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
        insertion_sort(arr,count);
        cout<<"Array after sorting: [ ";
        display_array(arr,count);
        cout<<"]"<<endl;
}