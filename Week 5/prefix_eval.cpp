// Name : Ajoy A
// Registration no. : 220970030
// Program : Prefix evaluation
// Date : 27/02/2023

#include <iostream>
#include "../week4/my_stack.h"

#define MAX 50

using namespace std;


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


bool isOperator(char ch)
{
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;

  return false;
}


int evaluate_prefix(char pre[], int size)
{
                          Stack<int> st(MAX);
                          for(int i = size-1; i >= 0; i--)
                          {
                                char ch = pre[i];
                                if(isOperator(ch))
                                {
                                        int op1 = st.pop();
                                        int op2 = st.pop();
                                        st.push(calculate(op1, ch, op2));
                                }else{
                                        st.push((int)ch - (int)'0'); // Parsing 'int' to int
                                }
                          }

                          return st.pop();
}



int main()
{
  char pre[MAX];
  cout<<"Enter infix expression: ";
  cin>>pre;
  int size = 0;
  while(pre[size] != '\0')
        size++;
  cout<<"Result = "<<evaluate_prefix(pre, size)<<endl;
}

