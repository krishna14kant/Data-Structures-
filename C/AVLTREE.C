#include<stdio.h>
#include<stdlib.h>
int num=0;
struct node
{
int value;
struct node *right;
struct node *left;
};
struct node *leftrotation(struct node *root)
{
  struct node *t;
  t=root->left;
  root->left=t->right;
  t->right=root;
  return t;
}
struct node *rightrotation(struct node *root)
{
  struct node *t;
  t=root->right;
  root->right=t->left;
  t->left=root;
  return t;
}

int max(int a,int b)
{
  if(a>b)
  return a;
  else
  return b;
}
int height(struct node *root)
{ if(root==NULL)
  {
    return -1;
  }
  else if((root->right==NULL&&root->left==NULL))
{
  return 0;
}
  else
  {
  return 1+max(height(root->left),height(root->right));
}
}

void printlevel(struct node *root,int i)
{
  if(i==0)
  {
    if(root==NULL)
    {
      return;
    }
    else
    {
      printf("\t%d",root->value);
    }
  }
  else
  {
    printlevel(root->left,i-1);
    printlevel(root->right,i-1);
  }
}
void levelorder(struct node *root)
{
  int i,j;
  j=height(root);
  printf("\n");
  for(i=0;i<=j;i++)
  {
    printlevel(root,i);
    printf("\n");
  }

}

int balancefactor(struct node *root)
{
  return (height(root->left)-(height(root->right)));
}
struct node *insert(struct node *root,int val)
{
struct node *n;
n=(struct node *)malloc(sizeof(struct node));
n->value=val;
if(root==NULL)
{
root=n;
root->right=NULL;
root->left=NULL;
num++;
}
else if(val<root->value)
{
root->left=insert(root->left,val);
if(balancefactor(root)==2)
{
  if(val>=root->left->value)
  {
    root->left=rightrotation(root->left);
  }
  root=leftrotation(root);
}
}
else
{
root->right=insert(root->right,val);
if(balancefactor(root)==-2)
{
  if(val<root->right->value)
  {
    root->right=leftrotation(root->right);
  }
  root=rightrotation(root);
}
}
return root;
}
void inorder(struct node *h)
{
if(h==NULL)
{
return ;
}
else
{
inorder(h->left);
printf("\t%d",h->value);
inorder(h->right);
return;
}
}
void postorder(struct node *h)
{
if(h==NULL)
{
return ;
}
else
{
postorder(h->left);
postorder(h->right);
printf("\t%d",h->value);
return;
}
}
void preorder(struct node *h)
{
if(h==NULL)
{
return ;
}
else
{
printf("\t%d",h->value);
preorder(h->left);
preorder(h->right);
return;
}
}
struct node *minright(struct node *root)  //minimum value in right subtree which can replace root
{
  struct node *temp;
  temp=root->right;
  while(temp->left!=NULL)
  {
    temp=temp->left;
  }
  return temp;
}

struct node *maxleft(struct node *root)
{
  struct node *temp;
  temp=root->left;
  while(temp->right!=NULL)
  {
    temp=temp->right;
  }
  return temp;

}
struct node *delete(struct node *root,int val)   //delete function
{
  struct node *temp;
  int x,choice;
  if(root==NULL)
  {
    printf("\n--------------------------");
    printf("\nwe can not delete ");
  }

  else
  {
     if(root->value==val)    //when root is the node to be deleted
     {
       if(root->right==NULL&&root->left==NULL) //when root is the only node
       {
         free(root);
         root=NULL;
       }
       else if(root->right==NULL)         //when root is having left subtree only
       {
         temp=root->left;
         free(root);
         root=temp;
       }
       else if(root->left==NULL)       //when root is having only right subtree;
       {
         temp=root->right;
         free(root);
         root=temp;
       }
       else
       {
         printf("\nwhich value u want to see as root's value\n%d or %d",minright(root)->value,maxleft(root)->value);
         scanf("%d",&choice);
         if(choice==minright(root)->value)              //when we have to set root value to max value of left subtree
         {
        x=minright(root)->value;
        root->value=x;
        root->right=delete(root->right,x);
        if(balancefactor(root)==2)
        {
          if(balancefactor(root->left)==-1)
          {
            root->left=rightrotation(root->left);
          }
          root=leftrotation(root);
        }
      }
      else            //when we have to set root value to min value of right subtree
      {
        x=maxleft(root)->value;
        root->value=x;
        root->left=delete(root->left,x);
        if(balancefactor(root)==-2)
        {
          if(balancefactor(root->right)==1)
          {
            root->right=leftrotation(root->right);
          }
          root=rightrotation(root);
        }
      }
       }
     }
     else if(root->value>val)
     {
       root->left=delete(root->left,val);
       if(balancefactor(root)==-2)
       {
         if(balancefactor(root->right)==1)
         {
           root->right=leftrotation(root->right);
         }
         root=rightrotation(root);
       }
     }
     else
     {
       root->right=delete(root->right,val);
       if(balancefactor(root)==2)
       {
         if(balancefactor(root->left)==-1)
         {
           root->left=rightrotation(root->left);
         }
         root=leftrotation(root);
       }
     }
  }

  return root;
}

void main()
{
  int i,j;
  struct node *root;
  root=NULL;
  while(243)
  {
  printf("\n--------------------------");
  printf("\n1 for insert\n2 for display\n3 for delete\n4 for exit\n--------------------------\nenter choice:");
  scanf("%d",&i);
  if(i==1)
  {
    printf("\n--------------------------");
    printf("\n enter num:");
    scanf("%d",&j);
    root=insert(root,j);
  }
  else if(i==2)
  {
    printf("\n level order \n");
    levelorder(root);
    printf("\n in order");
    inorder(root);
    printf("\n preorder");
    preorder(root);
    printf("\n postorder");
    postorder(root);
  }
  else if(i==3)
  {
    printf("\n--------------------------");
    printf("\n enter num:");
    scanf("%d",&j);
    root=delete(root,j);
  }

  else if(i==4)
  {
    printf("\n thnaks for using this");
    break;
  }
  else
  {
    printf("\n enter valid choice");
  }

}
}
