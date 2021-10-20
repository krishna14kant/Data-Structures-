#include<bits/stdc++.h>
using namespace std;
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

node* create(int ino[], int pre[], int s, int e){
     static int i=0;
     if(s>e)
     return NULL;
     
     node* root = new node(pre[i]);
     int index =1;
     for(int j=s;j<=e;j++)
     {
          if(ino[j]==pre[i])
          {
               index = j;
               break;
          }
     }
     i++;
     root->left = create(ino,pre,s,index-1);
     root->right = create(ino,pre,index+1,e);
     return root;
}

void insert(node* &root, int key) 
{ 
    queue<node*> q; 
    
  if(root==NULL)
  {
       root = new node(key);
       return;
  }
  q.push(root);
    while (!q.empty()) { 
         node* root = q.front(); 
        q.pop(); 
  
        if (!root->left) { 
             if(key!=-1)
            root->left = new node(key);
            else
            root->left = NULL;
            break; 
        } else
            q.push(root->left); 
  
        if (!root->right) { 
            if(key!=-1)
            root->right = new node(key); 
            else
            root->right = NULL;
            break; 
        } else
            q.push(root->right); 
    } 
} 

void printtop(node* root){
     if(root==NULL)
     return;
     
     printtop(root->left);
     cout<<root->data<<" ";
}

void printtop2(node* root){
     if(root==NULL)
     return;
     cout<<root->data<<" ";     
     printtop(root->right);

}

int main(){
     int d;
   
       node* root = NULL;
     while(scanf("%d",&d)!=EOF)
     {
          insert(root,d);
     }
 
    printtop(root);
    printtop2(root->right);
}
