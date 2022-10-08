//inorder preorder and postorder traversals of the binary tree
//height of the binary tree
//level order traversal

#include <bits/stdc++.h>
using namespace std;
class binary_tree;
class node
{
    int data;
    node *left;
    node *right;

public:
    friend binary_tree;
    node()
    {
        left = right = NULL;
    }
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class binary_tree
{
    node *root;
    int lev,maxi;
    void inorder_helper(node *root);
    void preorder_helper(node *root);
    void postorder_helper(node *root);
    int height_helper(node *root);
    void current_level_helper(node* root,int lev);
    void levelorder_helper(node*root);
    bool checkbalanced(node * root);
    int diameter_helper(node* root,int &maxi);
    int maxPath_helper(node* root,int &maxi);

public:
    binary_tree()
    {
        root = NULL;
        lev=0;
        maxi=INT_MIN;
    }
    void inorder();
    void preorder();
    void postorder();
    void construct();
    void levelorder();
    void height();
    void current_level();
    bool check();
    void diameter();
    void maxPath();
};
void binary_tree::inorder_helper(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_helper(root->left);
    cout << root->data << " ";
    inorder_helper(root->right);
}
void binary_tree::inorder()
{
    inorder_helper(root);
}
void binary_tree::preorder_helper(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder_helper(root->left);
    postorder_helper(root->right);
}
void binary_tree::preorder()
{
    preorder_helper(root);
}
void binary_tree::postorder_helper(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder_helper(root->left);
    postorder_helper(root->right);
    cout << root->data << " ";
}
void binary_tree::postorder()
{
    postorder_helper(root);
}
void binary_tree::construct()
{
    node *temp = NULL;
    temp = new node(1);
    temp->left = new node(2);
    temp->right = new node(3);
    temp->right->left = new node(4);
    temp->right->right = new node(6);
    temp->right->left->left=new node(5);
    temp->right->left->left->left=new node(9);
    temp->right->right->right=new node(7);
    temp->right->right->right->right=new node(8);
    root = temp;
}
int binary_tree::height_helper(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int lheight=height_helper(root->left);
        int rheight=height_helper(root->right);
        if(lheight>rheight)
        {
            return lheight+1;
        }
        else
        {
            return rheight+1;
        }
    }
}
void binary_tree::height()
{
    cout<<height_helper(root)<<endl;
}
void binary_tree::current_level_helper(node* root,int lev)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        if(lev==1)
        {
            cout<<root->data<<" ";
        }
        else if(lev>1)
        {
            current_level_helper(root->left,lev-1);
            current_level_helper(root->right,lev-1);
        }
    }
}
void binary_tree::current_level()
{
    current_level_helper(root,lev);
}
void binary_tree::levelorder_helper(node* root)
{
    int h=height_helper(root);
    int i;
    for(i=1;i<=h;i++)
    {
        current_level_helper(root,i);
    }
}
void binary_tree::levelorder()
{
    levelorder_helper(root);
}
bool binary_tree::checkbalanced(node* root)
{
    if(root==NULL)
    {
        return true;
    }
    int lh=checkbalanced(root->left);
    if(lh==-1)
    {
        return false;
    }
    int rh=checkbalanced(root->right);
    if(rh==-1)
    {
        return false;
    }
    if(abs(lh-rh)>1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool binary_tree::check()
{
    checkbalanced(root);
}
int binary_tree::diameter_helper(node* root,int &maxi)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=diameter_helper(root->left,maxi);
    int rh=diameter_helper(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}
void binary_tree::diameter()
{
    cout<<"The diameter of the tree is:"<<diameter_helper(root,maxi);
}
int binary_tree::maxPath_helper(node* root,int &maxi)
{
    if(root==NULL)
    {
        return 0;
    }
    int lsum=max(0,maxPath_helper(root->left,maxi));
    int rsum=max(0,maxPath_helper(root->right,maxi));
    maxi=max(maxi,lsum+rsum+root->data);
    return (root->data)+max(lsum,rsum);
}
void binary_tree::maxPath()
{
    cout<<"The maximum path of the binary tree is:"<<maxPath_helper(root,maxi)<<endl;
}
int main()
{
    binary_tree b;
    b.construct();
    cout<<"The preorder traversal of binary tree is:";
    b.preorder();
    cout<<endl;
    cout<<"The postorder traversal of binary tree is:";
    b.postorder();
    cout<<endl;
    cout<<"The inorder traversal of binary tree is:";
    b.inorder();
    cout<<endl;
    cout<<"The height of the binary tree is:";
    b.height();
    cout<<endl;
    cout<<"The level order traversal is:";
    b.levelorder();
    cout<<endl;
    if(b.check())
    {
        cout<<"balanced"<<endl;
    }
    else
    {
        cout<<"not balanced"<<endl;
    }
    b.diameter();
    b.maxPath();
    return 0;
}