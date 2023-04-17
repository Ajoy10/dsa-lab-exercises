#include <iostream>
#include "my_stack.h"

using namespace std;
int main()
{

        int stack_size;

        cout<<"Enter the size of stack: ";
        cin>>stack_size;

        Stack<double> st(stack_size);

        int ch;

        string choices[] = {"Push","Pop","Peek", "Count","Display"};
        int ch_count = sizeof(choices)/sizeof(choices[0]);

        do{
                cout<<endl;
                for(int i = 0; i < ch_count; i++)
                        cout<<i+1<<"."<<choices[i]<<endl;
                cout<<"Enter your choice (0 to exit): ";
                cin>>ch;

                switch(ch)
                {
                        case 1: int val;
                                cout<<"Value to push: ";
                                cin>>val;
                                st.push(val);
                                break;
                        case 2: cout<<"Popped "<<st.pop()<<endl;
                                break;
                        case 3: cout<<"Peeked "<<st.peek()<<endl;
                                break;
                        case 4: cout<<"Count of stack = "<<st.count()<<endl;
                                break;
                        case 5: st.display();
                                break;
                        case 0: cout<<"Exiting..."<<endl;
                                break;
                        default:cout<<"Invalid choice!"<<endl;
                }

        }while(ch != 0);

}
