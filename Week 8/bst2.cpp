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

        void postorder_r(node* rt)
        {
                if(rt == NULL)
                {
                        return;
                }

                postorder_r(rt->left);
                postorder_r(rt->right);
                cout<<rt->data<<" ";

        }

        void preorder_r(node* rt)
        {
                if(rt == NULL)
                {
                        return;
                }

                cout<<rt->data<<" ";
                preorder_r(rt->left);
                preorder_r(rt->right);
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

        void postorder()
        {
                postorder_r(ROOT);
        }

        void preorder()
        {
                preorder_r(ROOT);
        }



};

int main()
{
        BST t;
        int count;
        cout<<"Enter no. of elements:";
        cin>>count;

        cout<<"Enter "<<count<<" elements: ";
        for(int i = 0; i < count; i++)
        {
                int ele;
                cin>>ele;
                t.insert(ele);
        }
        cout<<"Preorder: ";
        t.preorder();

        cout<<endl<<"Inorder: ";
        t.inorder();

        cout<<endl<<"Postorder: ";
        t.postorder();
        cout<<endl;

}
