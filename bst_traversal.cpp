#include<iostream>
#include<conio.h>
using namespace std;

struct node {
   int info;
   node *left;
   node *right;
};
struct node *root = NULL ,*temp=NULL;

 

//declare functions here below:
void createtree();
void traversetree();

void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout<<p->info<<endl;
        inorder(p->right);
    }
}
void preorder(node *p)
{    
    if (p != NULL)
    {
        cout<<p->info<<endl;
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->info<<endl;
    }
}

int main()
{
    long int a,b;
    again:
    cout<<"\n Enter the number of that operation that you want to perform:\n";
    cout<<"1:\tCreate a Binary Tree\n";
    cout<<"2:\tTraverse the nodes of binary tree\n";
    cout<<"3:\tExit\n";
    cin>>a;

    switch(a)
    {
        case 0: goto endst;
        case 1: createtree(); break;
        case 2: 
        cout<<"printing traversal in inorder\n";
        inorder(root);
        cout<<"printing traversal in preorder\n";
        preorder(root);
        cout<<"printing traversal in postorder\n";
        postorder(root);
        break;
        case 3: goto endst; break;

        default: cout<<"\n Enter a valid number:";
    }
    end:
    cout<<"\n Do you want to Continue then press 1 for Yes and 0 for No:";
    cin>>b;
    if(b==1){
        goto again;
    }else if(b==0){
        endst:
        exit(7);
    }else{
        cout<<"\n PLease Enter Valid number";
        goto end;
    }    
getch();
}

void createtree()
{
    int value;
    char choice='y';   
    while (choice=='y')
    {

        if (root == NULL)
        {
            root = new node;
            cout<<"Enter value of root node\n";
            cin>>root->info;
            root->right=NULL;
            root->left=NULL;
        }
        else
        {
            temp = root;
            cout<<"Enter value of node\n";
            cin>>value;
            while(true)
            {
                if (value < temp->info)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = new node;
                        temp = temp->left;
                        temp->info = value;
                        temp->left = NULL;
                        temp->right = NULL;
                        cout<<"Value entered in left\n";
                        break;
                    }
                    else if (temp->left != NULL)
                    {
                        temp = temp->left;
                    }
                }
                else if (value > temp->info)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = new node;
                        temp = temp->right;
                        temp->info = value;
                        temp->left = NULL;
                        temp->right = NULL;
                        cout<<"value entered in right\n";
		        break;
		    }
                    else if (temp->right != NULL)
                    {
                        temp = temp->right;
                    }
                 }
             }
        }
        cout<<"Do you want to insert new node (Press y for yes n for no) y/n\n";
        cin>>choice;
    }
}
 
