// Name : Ajoy A
// Register no. : 220970030
// Program : Postfix Evaluation
// Date : 27/02/2023

#include <iostream>
#include "../week4/my_stack.h"

using namespace std;

bool isOperator(char ch)
{
                          if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
                          return true;

                          return false;
}

int calculate(int op1, char op, int op2){
                          switch(op)
                          {
                                case '+': return op1 + op2;
                                case '-': return op1 - op2;
                                case '*': return op1 * op2;
                                case '/': return op1 / op2;
                                default: return 0;
                          }
}

int evaluate_postfix(char postfix[], int size)
{
                          Stack<int> st(50);
                          for(int i = 0; i < size; i++)
                          {
                                char ch = postfix[i];
                                //cout<<ch<<endl;
                                if(isOperator(ch))
                                {
                                        int op2 = st.pop();
                                        int op1 = st.pop();
                                        int res = calculate(op1, ch, op2);
                                        st.push(res);
                                }
                                else
                                {
                                        //cout<<(int)ch - (int)'0';
                                        st.push((int)ch - (int)'0');
                                }
                                //cout<<endl;
                                //st.display();
                          }
                          return st.pop();

}

int main()
{
                          char post[50];
                          cout<<"Enter postfix: ";
                          cin>>post;
                          int size = 0;
                          while(post[size] != '\0')
                                size++;
                          cout<<"Result: "<<evaluate_postfix(post,size)<<endl;
}
