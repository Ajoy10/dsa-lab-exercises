// Name: Ajoy A

#include <iostream>

using namespace std;

struct node {
    node* left;
    char data;
    node* right;
};

void display_list(node* list)
{
    node* temp = list;
    while(temp != NULL)
    {
        cout<<temp->data;
        node* tempRight = temp->right;
        while(tempRight != NULL)
        {
            cout<<"->"<<tempRight->data;
            tempRight = tempRight->right;
        }
        temp = temp->left;
        cout<<endl;
    }
}

void add_relation(node* list, char a, char b)
{
    node* temp = list;
    while(temp!= NULL) {
        if(temp->data == a)
            break;
        temp = temp->left;
    }
    if(temp!=NULL)
    {
        node* lastRel = temp->right;
        if(lastRel == NULL)
        {
            temp->right = new node;
            temp->right->data = b;
            cout<<"Added "<<a<<" at "<<b<<endl;
            temp->right->right = NULL;
        } else {
            while(lastRel->right != NULL) {
                lastRel = lastRel->right;
            }
            lastRel->right = new node;
            lastRel->right->data = b;
            cout<<"Added "<<a<<" at "<<b<<endl;
            lastRel->right->right = NULL;
        }
    }
}

void add_edge(node* list, char a, char b)
{
    add_relation(list, a, b);
    add_relation(list, b, a);
}


int main()
{
    cout<<"Enter no. of vertices: ";
    int vertCount;
    cin>>vertCount;
    node* adjMat;


    adjMat = new node;
    adjMat->data = 'A';
    adjMat->left = NULL;
    adjMat->right = NULL;


    for(int i = 1; i < vertCount; i++)
    {
        node* last = adjMat;
        while(last->left != NULL)
            last = last->left;
        last->left = new node;
        last = last->left;
        last->data = (char)(65 + i);
        last->right = NULL;
    }


    cout<<"Define edges: "<<endl;
    while(true)
    {
        cout<<"From, to: ";
        char a, b;
        cin >> a >> b;
        add_edge(adjMat, a, b);
        cout<<"Add more?(y/n) ";
        char ans;
        cin >> ans;
        if(ans != 'Y' && ans != 'y')
            break;

    }

    display_list(adjMat);


    /*
    cout<<"Define edges: "<<endl;
    for(int i = 0; i < vertCount; i++)
    {
            for(int j = 0; j < vertCount; j++)
            {
                    if(i == j)
                    {
                            adjMat[i][j] = 0;
                            continue;
                    }else{
                            cout<<"Is there a node from "<< (char)(65 + i)<<" to "<<(char)(65 + j)<<"? (Y/N)";
                            char ans;
                            cin>>ans;
                            if(ans == 'Y' || ans == 'y')
                            {
                                    adjMat[i][j] = 1;
                            }else{
                                    adjMat[i][j] = 0;
                            }

                    }

            }
    }

    cout<<endl;
    for(int i = 0; i < vertCount; i++)
    {
            for(int j = 0; j < vertCount; j++)
            {
                    cout<<adjMat[i][j]<<" ";
            }
            cout<<endl;
    }
    */
}
