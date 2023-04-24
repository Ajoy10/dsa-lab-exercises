// Name: Ajoy A
// Reg. no.: 220970030
// Program title: Implementation of quicksort
// Date: 24/04/2023

#include <iostream>
#include "../common/common.cpp"

#define MAX 50
using namespace std;

int partition(int arr[], int left, int right, int pivot)
{
    int i = left;
    int j = right - 1;
    while(true)
    {
        // Find the element greater than pivot from left
        while(arr[i] < pivot)
        {
            i++;
        }

        // Find the element lesser than pivot from right
        while(j > 0 && arr[j] > pivot)
        {
            j--;
        }

        if(i>=j)
            break;
        else {

            // swap i,j
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    }

    // swap i, right
    int temp = arr[i];
    arr[i] = arr[right];
    arr[right] = temp;
    return i;
}

void quicksort(int arr[], int left, int right)
{
    if(right-left <= 0)
    {
        return;
    } else {
        int pivot = arr[right];
        int part = partition(arr, left, right, pivot);
        quicksort(arr, left, part - 1);
        quicksort(arr, part + 1, right);
    }
}

int main()
{
    int arr[MAX], count;
    input_array(arr, count);
    cout<<"Array: [";
    display_array(arr, count);
    cout<<" ]"<<endl;
    quicksort(arr, 0, 5);

    cout<<"Array after sorting: [";
    display_array(arr, count);
    cout<<" ]"<<endl;

}
