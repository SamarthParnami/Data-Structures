#include <bits/stdc++.h>
#include<queue>

using namespace std;


class BinarySearchTree{
 public:
BinarySearchTree* left;
BinarySearchTree* right;

    int val;
    BinarySearchTree(int val)
    {
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
    void insertion(int val)
    {
        BinarySearchTree* node=new BinarySearchTree(val);
        if(this->left==nullptr&&this->val>=val)
        {
                left=node;
                return;
        }
        if(this->right==nullptr&&this->val<=val)
        {
            right=node;
            return;
        }
        if(this->left!=nullptr&&val<=this->val)
        {
            delete node;
            this->left->insertion(val);
        }
        if(this->right!=nullptr&&val>=this->val)
        {
            delete node;
            this->right->insertion(val);
        }
    }
    BinarySearchTree* searchVal(int val)
    {
        if(this->val<val&& this->right==nullptr)
        {
            return nullptr;
        }
        else if(this->val>val&&this->left==nullptr)
        {
            return nullptr;
        }
        if(this->val==val)
        {
            return this;
        }
        else if(this->val>val)
        {
            return this->left->searchVal(val);
        }
        else if(this->val<val)
        {
            return this->right->searchVal(val);
        }
    }
    int searchRightMost()
    {
        if(this->right->left==nullptr&&this->right->right==nullptr)
        {
            int value= this->right->val;
            delete this->right;
            this->right=nullptr;
            return value;
        }
        else
        {
            return this->right->searchRightMost();
        }
    }
    void deletion(int val)
    {
        BinarySearchTree* node=this->searchVal(val);
        if(node->left==nullptr&&node->right==nullptr)
        {
            delete node;
            return;
        }
        else if(node->left==nullptr|| node->right==nullptr)
        {
            if(left)
            {
                node->val=left->val;
                delete left;
            }
            else
            {
                node->val=right->val;
                delete right;
            }
        }
        else
        {
            node->val=this->searchRightMost();
        }

    }
};
void printVector(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    BinarySearchTree root(9);
    root.insertion(1);
    root.insertion(100);
    root.insertion(10);
    root.insertion(55);
    root.insertion(4);
    root.insertion(145);
    root.insertion(-1);



    cout<<"Editor--Samarth Parnami"<<endl;


    return 0;
}
