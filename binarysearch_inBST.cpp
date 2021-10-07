#include<iostream>
using namespace std;
#include<queue>
template <typename t>
class binarytree{
	public:
		t data;
		binarytree* left;
		binarytree* right;
		binarytree(t data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
		~binarytree()
		{
			delete left;
			delete right;
		}
		
};
binarytree<int>* input2()
{
	queue<binarytree<int>*> q;
	int rdata;
	cout<<"Enter data"<<endl;
	cin>>rdata;
	binarytree<int>* root=new binarytree<int>(rdata);
	q.push(root);
	while(q.size()!=0)
	{
		binarytree<int>* front=q.front();
		q.pop();
		cout<<"Enter left child of "<<front->data<<endl;
		int leftchild;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			binarytree<int>* n=new binarytree<int>(leftchild);
			front->left=n;
			q.push(n);
		} 
		
		cout<<"Enter right child of "<<front->data<<endl;
		int rightchild;
		cin>>rightchild;
		if(rightchild!=-1)
		{
			binarytree<int>* n=new binarytree<int>(rightchild);
			front->right=n;
			q.push(n);
		}
	}
	return root;
}
void print(binarytree<int>* root)
{
	queue<binarytree<int>*> q;
	q.push(root);
	while(q.size()!=0)
	{
		binarytree<int>* front=q.front();
		q.pop();
		cout<<front->data<<":";
		if(front->left!=NULL)
		{
			cout<<"L"<<front->left->data;
			q.push(front->left);
		}
		
		if(front->right)
		{
			cout<<"R"<<front->right->data;
			q.push(front->right);
		}
		cout<<endl;
	} 
}


bool bsearch(binarytree<int>* root,int data1)
{
	if(root==NULL)
	{
		return false;
	}
	if(root->data==data1)
	{
		return true;
	}
	else if(data1<root->data)
	{
		bsearch(root->left,data1);
	}
	else
	{
		bsearch(root->right,data1);
	}
}

int main()
{
	// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
	binarytree<int>* root1=input2();
	print(root1);
	int x;
	cout<<endl<<"Enter element to be searched : "<<endl;
	cin>>x;
	bool y=bsearch(root1,x);
	if(y==1)
	{
		cout<<"Element Present"<<endl;
	}
	else
	{
		cout<<"Element Not Present"<<endl;
	}
}
