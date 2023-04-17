#include <iostream>
#include "my_linked_list.h"
using namespace std;

node* reverse(node* NODE, node* &HEAD)
{
        if(NODE == NULL)
        {
                return NULL;
        }else if(NODE->next == NULL)
        {
                HEAD = NODE;
                return NODE;
        }else{
                node* n1 = reverse(NODE->next, HEAD);
                n1->next = NODE;
                NODE->next = NULL;
                return NODE;

        }

}

int main()
{
        node* HEAD = NULL;
        insert_end (HEAD, 10);
        insert_end (HEAD, 20);
        insert_end (HEAD, 30);
        insert_end (HEAD, 40);
        insert_end (HEAD, 50);
        display(HEAD);

        cout<<"Reversed ";
        reverse(HEAD, HEAD);
        display(HEAD);
}
