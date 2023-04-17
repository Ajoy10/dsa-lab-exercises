#include<iostream>
using namespace std;
int main()
{
    int array[200];
    int i,j,min,temp,n;
    cout<<"ENTER THE NO. OF THAT ARE TO BE SORTED:\n";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"ENTER THE ELEMENT:";
            cin>>array[i];
    }
    for(i=0;i<n-1;i++)
    {
        min = i;
    for(j=i+1;j<n;j++)
    {
        if(array[j]<array[min])
        {
            min = j;
        }
    }
    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
}
for(i=0;i<n;i++)
{
    cout<<array[i]<<",";
}
}
