// Name: Ajoy A
// Reg. no. : 220970030
// Program : Binary Searching using Iterations
// Date : 17/04/2023


#include <iostream>
#include "../common/common.cpp"
#define MAX 50
using namespace std;

int binary_search(int arr[], int target, int count)
{
        int upper = count, lower = 0, mid;
        do
        {
                mid = (upper + lower)/2;
                if(arr[mid] == target)
                {
                        return mid;
                }else if(target > arr[mid])
                {
                        lower = mid + 1;
                }else{
                        upper = mid - 1;
                }
        }while(upper >= lower);

        return -1;
}

int main()
{
        cout<<"Enter sorted array:"<<endl;
        int arr[MAX], count, target;
        input_array(arr, count);
        cout<<"Enter target: ";
        cin>>target;
        int result = binary_search(arr, target, count);
        if(result==-1)
        {
                cout<<target<<" not found!"<<endl;
        }else
        {
                cout<<target<<" found at index "<<result<<endl;
        }
}