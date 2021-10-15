#include <bits/stdc++.h>
using namespace std;
struct node;
node *insert(node *, int);
int height(node *);
bool search(node *, int);

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

node *insert(node *root, int x)
{
    node *newNode = new node(x);
    if (root == NULL)
        return newNode;
    else if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
}

bool search(node *root, int x)
{
    if (root->data == x)
        return true;
    else if (x < root->data && root->left != NULL)
        return search(root->left, x);
    else if (x > root->data && root->right != NULL)
        return search(root->right, x);
    else
        return false;
}

int height(node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}
void print(node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main()
{
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    cout << "\nInorder traversal of tree is : ";
    print(root);
    cout << "\nHeight of tree is : " << height(root);
    if (search(root, 65))
        cout << "\nKey found!";
    else
        cout << "\nKey not found!";
    return 0;
}
