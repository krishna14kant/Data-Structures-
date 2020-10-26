#include<stdio.h> 
#include<stdlib.h> 
struct node  
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
  
/* newNode() allocates a new node with the given data and NULL left and  
right pointers. */
struct node* newNode(int data) 
{ 
// Allocate memory for new node  
struct node* node = (struct node*)malloc(sizeof(struct node)); 
  
// Assign data to this node 
node->data = data; 
  
// Initialize left and right children as NULL 
node->left = NULL; 
node->right = NULL; 
return(node); 
} 
  
  
int main() 
{ 
/*create root*/
struct node *root = newNode(1);  

  
root->left     = newNode(2); 
root->right     = newNode(3); 

  
root->left->left = newNode(4); 

  
getchar(); 
return 0; 
} 
