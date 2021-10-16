#include <iostream>
#include<cmath>
using namespace std;
class node
{
    public:
        int data;
        node* left;
        node* right;
        node(int d)
        {
            data=d;
            left=NULL;
            right=NULL;
        }
};
node* buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
void print(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
static int tilt=0;
int tilttree(node* root)
{
	
	if(root=NULL)
	{
		return 0;
	}
	
	int ls=tilttree(root->left);
	int rs=tilttree(root->right);

	int  lotlt=abs(ls-rs);
	tilt+=lotlt;
	
	int ts=ls+rs+root->data;
	return ts;
}
int main() 
{
    node* root=buildtree();
    print(root);
    cout<<endl;
   cout<< tilttree(root);
    
}
/*
i/p:
50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
o/p:
50 25 37 75 62
*/

