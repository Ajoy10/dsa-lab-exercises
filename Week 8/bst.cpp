#include <iostream>
using namespace std;

struct node
{
        node* left;
        int data;
        node* right;
};

class BST{
        node* ROOT;
        private:

        void inorder_r(node* rt)
        {
                if(rt == NULL)
                        return;
                inorder_r(rt->left);

                cout<<rt->data<<" ";
                inorder_r(rt->right);
        }

        node* insert_r(node* rt,int val)
        {
                if(rt == NULL)
                {
                        node* newNode = new node;
                        newNode->data = val;
                        newNode->left = NULL;
                        newNode->right = NULL;
                        return newNode;
                }
                else if(val < rt->data)
                {
                        rt->left = insert_r(rt->left, val);
                }else{
                        rt->right = insert_r(rt->right, val);
                }

                return rt;
        }

        public:
        BST()
        {
                ROOT = NULL;
        }


        void insert(int val){
                ROOT = insert_r(ROOT, val);
        }


        void inorder()
        {
                inorder_r(ROOT);
        }



};

int main()
{
        BST t;
        cout<<"Enter no. of elements:"


        t.inorder();

}
