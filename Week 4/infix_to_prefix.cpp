// Name: Ajoy
// Register no. : 220970030
// Program : Infix to postfix
// Date : 27/02/2023

#include <iostream>
#include "my_stack.h"

#define MAX 50

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

void leftConcat(string &str, char pre )
{
                          str = pre+str;
}

string infix_to_prefix(char infix[], int size){
                          Stack<char> st(MAX);
                          string prefix = "";

                          for(int i = size-1; i >= 0; i--)
                          {
                                char ch = infix[i];

                                if(ch==')')
                                {
                                        st.push(ch);
                                }
                                else if(ch=='(')
                                {
                                        char popped = st.pop();
                                        while(!st.isEmpty() && popped != ')')
                                        {
                                                leftConcat(prefix, popped);
                                                popped = st.pop();
                                        }
                                }
                                else if(isOperator(ch))
                                {
                                        while(!st.isEmpty() && (priority(st.peek()) > priority(ch)))
                                        {
                                                char popped = st.pop();
                                                leftConcat(prefix, popped);
                                        }
                                        st.push(ch);
                                }else{
                                        leftConcat(prefix, ch);
                                }

                          }

                          while(!st.isEmpty())
                          {
                                leftConcat(prefix, st.pop());
                          }

                          return prefix;
}

int main()
{
                          char inf[MAX];
                          cout<<"Enter infix: ";
                          cin>>inf;
                          int size = 0;
                          while(inf[size] != '\0')
                                size++;
                          string prefix = infix_to_prefix(inf,size);
                          cout<<"Prefix = "<<prefix<<endl;
}
