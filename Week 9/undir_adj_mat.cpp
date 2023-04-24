// Name: Ajoy A

#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter no. of vertices: ";
    int vertCount;
    cin>>vertCount;
    int adjMat[vertCount][vertCount] = {{0}};
    cout<<"Define edges: "<<endl;
    for(int i = 0; i < vertCount; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(i == j)
            {
                adjMat[i][j] = 0;
                continue;
            } else {
                cout<<"Is there a node between "<< (char)(65 + i)<<" and "<<(char)(65 + j)<<"? (Y/N)";
                char ans;
                cin>>ans;
                if(ans == 'Y' || ans == 'y')
                {
                    adjMat[i][j] = 1;
                    adjMat[j][i] = 1;
                } else {
                    adjMat[i][j] = 0;
                    adjMat[j][i] = 0;
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
}
