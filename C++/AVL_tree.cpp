#include <iostream>
using namespace std;
class BST
{
public:
    BST *left;
    int data;
    BST *right;
    BST()
    {
        data = 0;
        left = right = NULL;
    }
};

int Height(BST *root)
{
    if (!root)
    return 0;

    int L = Height(root->left);
    int R = Height(root->right);

    
    return ((L >= R) ? L+1: R+1 );
}
void printLevel(BST *root, int n)
{
    if (!root)
        return;
    if (n == 0)
    {
        cout << root->data << endl;
        return;
    }
    else
    {
        printLevel(root->left, n - 1);
        printLevel(root->right, n - 1);
    }
}

void LevelOrder(BST *root)
{
    // using stack memory ;
    int height = Height(root);
    for (int i = 0; i < height; i++)
        printLevel(root, i);
}

void Print2D(BST* root,int space){
    if(!root)
    return;
    space+=5;
    Print2D(root->right,space);
    cout << endl;
    for(int i=5;i<space; i++)
    cout << " ";
    cout << root->data <<endl;
    Print2D(root->left,space);
}

int getBF(BST* root){
    return ((Height(root->left)) - (Height(root->right)));
}

void LLrotation(BST* &root){
    BST* n2 = root->left;
    BST* c3 = n2->right;

    n2->right = root;
    root->left =c3;
    root = n2;
}
void RRrotation(BST* &root){
    BST* n2 = root->right;
    BST* c3 = n2->left;

    n2->left = root;
    root->right = c3;
    root = n2;
}
void Insert(BST *&root, int data)
{

    if (!root){
    BST *newNode = new BST;
    newNode->data = data;
    root = newNode;
    return;
    }

    if (data > root->data){
    Insert(root->right,data);
    }

    else if (data < root->data){
    Insert(root->left,data);
    }

    else{
    cout << "Exist :"<<endl;
    }

    // AVL PART :

    int bf = getBF(root);
    
    if(bf > 1 && data < root->left ->data){
     LLrotation(root);    
    }
    else if(bf > 1 && data > root->left->data){
        // LRrotation(root);
        RRrotation(root->left);
        LLrotation(root);
    }
    else if(bf < -1 && data > root->right->data){
     RRrotation(root);
    }
    else if(bf < -1 && data < root->right->data){
        // RLrotaion(root);
        LLrotation(root->right);
        RRrotation(root);
    }
    else
    return;
}
BST * findMax(BST* root){
    while(root->right)
    root= root->right;

    return root;
}
void Delete(BST* &root, int data){
  
    if(!root)
    return;

    if(data < root->data )
    Delete(root->left, data);

    else if(data > root->data )
    Delete(root->right,data);
    else{
        if(root->right && root->left){
            BST* temp = findMax(root->left);
            root->data = temp->data;
            Delete(root->left,temp->data);
        }
        else{
            BST* temp = root;
            if(!root->left)
            root = root->right;
            else if(!root->right)

            root = root->left;
            delete temp;
            return;
        }
    }
    int bf = getBF(root);
    if(bf >= 2 && getBF(root->left) >= 0){
    LLrotation(root);
    }
    else if(bf >= 2 && getBF(root->left) <= 0 ){
    RRrotation(root->left);
    LLrotation(root);
    }
    else if(bf <= -2 && getBF(root->right) <= 0)
    RRrotation(root);
    else if(bf <= -2 && getBF(root->right) >= 1){
        LLrotation(root->right);
        RRrotation(root);
    }
    return;
}

BST * Find(BST *root, int data){
    if(!root)
    return NULL;

    if(data < root->data)
    return Find(root->left, data);
    else if(data > root->data)
    return Find(root->right,data);
    else
    return root;
}
void DeleteTree(BST* &root){
    if(!root)
    return;
    DeleteTree(root->left);
    DeleteTree(root->right);
    BST* temp = root;
    root= NULL;
    delete temp;
    return;
}
int main()
{
    BST *root = NULL;
    int ch;
    while (1)
    {
        cout << "...1:insert 2:Find 3:Delete 4:Print2d 5:Height 6:LevelOrder 8:DeleteTree 9:EXIT..." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter Value " << endl;
            cin >> ch;
            Insert(root, ch);
            break;
        }
        
        case 2:
        {
            cout << "Enter Value " << endl;
            cin >> ch;
            if (Find(root, ch))
                cout << "Found: ";
            else
                cout << "Not found " << endl;
            break;
        }
        case 3:
        {
            cout << "Enter Value " << endl;
            cin >> ch;
            Delete(root, ch);
            break;
        }
        case 4:
        Print2D(root,5);
            cout   << endl;
            break;
        case 5:
            cout << "Height: " << Height(root)-1<< endl;
            break;
        case 6:
            cout << "Level order: " << endl;
            LevelOrder(root);
            break;
         case 8:
            DeleteTree(root);
            break;
        case 9:
            cout << "Exit code 000 " << endl;
            return 0;
        default:
            cout << "Wrong Choise " << endl;
        }
    }
}
