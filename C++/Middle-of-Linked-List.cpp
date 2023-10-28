#include <iostream>

using namespace std;
class Node { 
    public:
    int key; 
    Node* next; 
}; 

void push(Node** head, int key) { 
    Node* new_node = new Node();
    new_node->key = key; 
    new_node->next = *head; 
    *head= new_node; 
} 
int middle(Node** head){
    if(head == NULL)
        return -1;
    Node* slow = *head;
    Node* fast = *head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow->key;
}

int main(){
    Node* head = NULL; 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 4); 
    push(&head, 5); 
    push(&head, 6);
    
    cout<<middle(&head);
    return 0;
}
