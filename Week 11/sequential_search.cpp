// Name: Ajoy A
// Reg. no. : 220970030
// Program : Sequential Searching
// Date : 17/04/2023


#include <iostream>
#include "../common/common.cpp"
#define MAX 50
using namespace std;

int sequential_search(int arr[], int target, int count)
{
        for(int i = 0; i < count; i++)
        {
                if(arr[i] == target)
                {
                        return i;
                }
        }

        return -1;
}

int main()
{
        int arr[MAX], count, target;
        input_array(arr, count);
        cout<<"Enter target: ";
        cin>>target;
        int result = sequential_search(arr, target, count);
        if(result==-1)
        {
                cout<<target<<" not found!"<<endl;
        }else
        {
                cout<<target<<" found at index "<<result<<endl;
        }
}