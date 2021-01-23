#include <bits/stdc++.h>
#include<queue>

using namespace std;

class BinaryTree{
public:
    int val;
    BinaryTree* left;
    BinaryTree* right;
    queue<vector<BinaryTree*>> inserts;
    BinaryTree(int val,BinaryTree* l=nullptr,BinaryTree* r=nullptr)
    {
        this->val=val;
        left=l;
        right=r;
        vector<BinaryTree*> temp(1,this);
        inserts.push(temp);
    }
    void setLeftNode(BinaryTree* l)
    {
        left=l;
    }
    void setRightNode(BinaryTree* r)
    {
        right=r;
    }
    int toInt(string a)
    {
        int num=0;
        for(int i=0;i<a.length();i++)
        {
            num*=10;
            num+=(a[i]-'0');
        }
        return num;
    }
    void insertNodes(string nodes)      //conatins values like "1,2,3,null,5,9, ...."
    {
        vector<string> values;
        string temp;
        for(int i=0;i<nodes.length();i++) // seperating values of nodes into separate strings
        {
            if(nodes[i]==',')
            {
                values.push_back(temp);
                temp.resize(0);
            }
            else
            {
                temp.push_back(nodes[i]);
            }
        }

        for(int i=0;i<values.size();i++)
        {
            if(inserts.front().size()==2)
            {
                if(values[i]=="null"||values[i]=="Null"||values[i]=="nullptr")
                {
                    inserts.front()[0]->left=inserts.front()[1];
                    inserts.front()[0]->right=nullptr;
                    inserts.pop();
                }
                else
                {
                    BinaryTree* node=new BinaryTree(toInt(values[i]));
                    inserts.front().push_back(node);
                    inserts.front()[0]->setLeftNode(inserts.front()[1]);
                    inserts.front()[0]->setRightNode(node);
                    vector<BinaryTree*> temp(1,node);
                    inserts.push(temp);
                    inserts.pop();

                }
            }
            else
            {
                if(values[i]=="null"||values[i]=="Null"||values[i]=="nullptr")
                {
                    inserts.front().push_back(nullptr);
                }
                else
                {
                    BinaryTree* node=new BinaryTree(toInt(values[i]));
                    inserts.front().push_back(node);
                    vector<BinaryTree*> temp(1,node);
                    inserts.push(temp);
                }
            }
        }
    }
    vector<int> preorderTraversal(BinaryTree* root)
    {
        vector<int> ans;
        if(root!=nullptr)
        {
            ans.push_back(root->val);
            if(root->left!=nullptr)
            {
                vector<int> l=preorderTraversal(root->left);
                ans.insert(ans.end(),l.begin(),l.end());
            }

            if(root->right!=nullptr)
            {
                vector<int> r=preorderTraversal(root->right);
                ans.insert(ans.end(),r.begin(),r.end());
            }
        }

        return ans;
    }
    vector<int> inorderTraversal(BinaryTree* root)
    {
        vector<int> ans;
        if(root!=nullptr)
        {

            if(root->left!=nullptr)
            {
                vector<int> l=inorderTraversal(root->left);
                ans.insert(ans.end(),l.begin(),l.end());
            }
            ans.push_back(root->val);
            if(root->right!=nullptr)
            {
                vector<int> r=inorderTraversal(root->right);
                ans.insert(ans.end(),r.begin(),r.end());
            }
        }

        return ans;
    }
    vector<int> postorderTraversal(BinaryTree* root)
    {
        vector<int> ans;
        if(root!=nullptr)
        {

            if(root->left!=nullptr)
            {
                vector<int> l=postorderTraversal(root->left);
                ans.insert(ans.end(),l.begin(),l.end());
            }

            if(root->right!=nullptr)
            {
                vector<int> r=postorderTraversal(root->right);
                ans.insert(ans.end(),r.begin(),r.end());
            }
            ans.push_back(root->val);
        }

        return ans;
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
    BinaryTree root(1);
    root.insertNodes("2,3,4,5,6,null,7,8,9");
    printVector(root.inorderTraversal(&root));
    printVector(root.postorderTraversal(&root));
    printVector(root.preorderTraversal(&root));


    cout<<"Editor--Samarth Parnami"<<endl;


    return 0;
}
