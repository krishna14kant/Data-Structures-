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

node* insert(node* root, int key) 
{ 
      queue<node*> q; 
      root = new node(key);
      int d;
      node * cur = root;
      root = cur;
      int c=0;
      while (scanf("%d",&d)!=EOF) { 
            
            if(d!=-1)
            {
                  if(c==0)
                  {
                        cur->left = new node(d);
                        q.push(cur->left);
                        c++;
                  }
                  else 
                  {
                        cur->right = new node(d);
                        q.push(cur->right);
                        c=0;
                        if(q.front())
                        cur = q.front();
                        q.pop();
                  }
            }
            else
            {
                  if(c==0)
                  c++;
                  else
                  {
                        c=0;
                        if(q.front())
                        cur = q.front();
                        q.pop();
                  }
            }
             if(q.empty())
                  return root;
      } 
      return root;
} 

void bottomhelp(node* root, map<int,pair<int,int> > &h,int d,int l)
{
      if(root==NULL)
      return;
      
      if(h.count(d)==0)
      h[d]={root->data,l};
      
      else if(h.count(d)!=0 && l>= h[d].second)
      h[d] = {root->data,l};
      
      
      bottomhelp(root->left,h,d-1,l+1);
      bottomhelp(root->right,h,d+1,l+1);
      
}

void bottom(node* root)
{
      if(root==NULL)
      return;
      map<int,pair<int,int> > h;
      bottomhelp(root,h,0,0);
      for(auto v:h)
      cout<<v.second.first<<" ";
}

int main(){
     int d;
   
       node* root = NULL;
       cin>>d;
       root = insert(root,d);
       bottom(root);
}
