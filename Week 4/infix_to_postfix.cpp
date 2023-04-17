// Name: Ajoy A
// Register no.: 220970030
// Program title: Infix to Postfix conversion
// Date: 20/02/2023


#include <iostream>
#include <string.h>
#include "my_stack.h"

#define MAX 30

using namespace std;

int priority(char ch)
{
                          switch(ch)
                          {
                                case '+':
                                case '-':return 1;
                                case '*':
                                case '/':return 2;
                                default: return 0;
                          }
}

bool isOperator(char ch)
{
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;

  return false;
}

void concat(string &p, char ch)
{
                          p += (ch);
//                        cout<<endl<<p<<endl;
}

string infixToPostfix(char infix[], int size)
{
                          Stack<char> st(MAX);
                          string postfix = "";

                          for(int i = 0; i < size; i++)
                          {

                                char ch = infix[i];

                                if(ch == '(')
                                {
                                        st.push(ch);
                                }else if(ch == ')')
                                {
                                        char popped = st.pop();

                                        while(popped != '(')
                                        {
                                                concat(postfix, popped);
                                                popped = st.pop();
                                        }
                                }else if(isOperator(ch))
                                {
                                        char stackTop = st.peek();
                                        while(!st.isEmpty() && (priority(ch) <= priority(stackTop)))
                                        {
                                                char popped = st.pop();
                                                concat(postfix, popped);
                                                stackTop = st.peek();
                                        }

                                        st.push(ch);
                                }else{
                                        concat(postfix, ch);
                                }


                                //cout<<ch<<"\t"<<postfix<<"\n";
                                //st.display();

                          }

                          while(!st.isEmpty())
                          {
                                char popped = st.pop();
                                concat(postfix, popped);
                          }

                          return postfix;
}

int main()
{
  char infix[MAX];
  cout<<"Enter infix expression: ";
  cin>>infix;
  int size = 0;
  while(infix[size] != '\0')
        size++;
//                        cout<<size<<endl;
  cout<<infixToPostfix(infix, size)<<endl;
}
