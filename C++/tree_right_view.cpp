#include<bits/stdc++.h>
using namespace std;
#define MAX 500

class node{
  public:
     int data;
     node* left;
     node* right;
     
     node(int d){
          data = d;
          left = right = NULL;
     }
};

node* insertValue(node* root, int value, queue<node *>& q) 
{ 
    node* n = new node(value); 
    if (root == NULL) 
        root = n;   
    else if (q.front()->left == NULL) 
        q.front()->left = n; 
    else { 
        q.front()->right = n; 
        q.pop(); 
    } 
  
    q.push(n); 
    return root; 
} 
  
node* createTree(int arr[], int n) 
{ 
    node* root = NULL; 
    queue<node*> q; 
    for (int i = 0; i < n; i++) 
      root = insertValue(root, arr[i], q); 
    return root; 
} 


node *buildtree()
{
    int count=0;
    int d;
    queue<node*> q;

    cin>>d;
    node *root=new node(d);
    node *cur=root;
    root=cur;
    while(1)
    {
        cin>>d;
        if(d!=-1)
        {
            if(count==0)
            {
                cur->left=new node(d);
                count++;
                q.push(cur->left);
        
            }
            else if(count==1)
            {
                cur->right=new node(d);
                q.push(cur->right);
                count=0;
                if(q.front())
                cur=q.front();
                
                q.pop();
            }
        } 
        else if(d==-1)
        {
            if(count==0)
            count++;
            else
            {
                count=0;
                if(q.front())
                cur=q.front();
                
                q.pop();
            }
        }       
        if(q.empty())
        return root;
    }
}

void right(node* root)
{
      queue<node*> q;
      q.push(root);
      q.push(NULL);
      while(!q.empty())
      {
            node* f = q.front();
            q.pop();
            
            if(f->left)
            q.push(f->left);
            if(f->right)
            q.push(f->right);
            
            if(q.front()==NULL)
            {
                  cout<<f->data<<" ";
                  q.pop();
                  if(!q.empty())
                  {
                        q.push(NULL);
                  }
            }
      }
}

int main(){

     node* root = buildtree();
      right(root);
}
