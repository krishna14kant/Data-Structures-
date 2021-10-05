Linked List reversal
#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
     int val;
     Node* next;
};

Node* Add(Node* head,int c)
{
    Node* nd = new Node();
    nd->val = c;
    nd->next = head;
    head = nd;
    return head;
}

Node* reverse(Node* h)
{
        Node* cur = h, *prev = NULL, *next = NULL;
        while (cur != NULL) 
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        h = prev;
        return h;
}

void print(Node* h){
     Node* traversal = h;
     while(traversal)
    {
      cout << traversal->val << ' ';
      traversal=traversal->next;
    }
    cout << '\n';
}

int main(){
    cin.tie(0);
    cout.tie(0);
    int n,v;
    cout << "Enter the Number of nodes you want in your Linked List\n";
    cin >> n;
    cout << "Enter the values\n";
    cin >> v;
    
    Node* Head = new Node();
    Head->val = v;
    Head->next = NULL;
    
    for(int i=1;i<n;i++)
    {
        cin >> v;
        Head=Add(Head,v);
    }
    
    cout <<"Your Linked list Before Reversal\n";
    print(Head);
    
    cout <<"Your Linked list After Reversal\n";
    Head=reverse(Head);
    print(Head);
    return 0;
}
