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

class hbpair
{
	public:
		int height;
		bool balanced;
};
hbpair is_balanced(node* root)
{
	hbpair p;
	if (root==NULL)
	{
		p.height=0;
		p.balanced=true;
		return p;
	}
	hbpair ls=is_balanced(root->left);
	hbpair rs=is_balanced(root->right);
	p.height=max(ls.height,rs.height)+1;
	if(abs(ls.height-rs.height)<=1 and ls.balanced and rs.balanced)
	{
		p.balanced=true;
	}
	else
	{
		p.balanced=false;
	}
	return p;
}
int main() 
{
    node* root=buildtree();
    print(root);
    cout<<endl;
    if(is_balanced){
    	cout<<"balanced";
	}
	else
	{
		cout<<"not balanced";
	}
	return 0;   
}
/*
i/p:
50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
o/p:
50 25 37 75 62
balanced
*/

