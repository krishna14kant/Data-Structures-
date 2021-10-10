// C++ program to rotate a linked list counter clock wise
 
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
class Node {
public:
    int data;
    Node* next;
};

/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1 = loop_node;
    struct Node* ptr2 = loop_node;
 
    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }
 
    // Fix one pointer to head
    ptr1 = head;
 
    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;
 
    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
 
    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
 
    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
}

bool detectAndRemoveLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;
 
    // Iterate and find if loop exists or not
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
 
        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);
 
            /* Return 1 to indicate that loop is found */
            return true;
        }
    }
 
    /* Return 0 to indicate that there is no loop*/
    return false;
}
 
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Function to print linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* start = NULL;
 
    int cnt;
    cout << "Enter number of nodes: ";
    cin >> cnt;
    cout << endl;
    
    for(int i=0;i<cnt;i++)
    {
        cout << "Enter node" << (i+1) << ": ";
        int data;
        cin >> data;
        push(&start, data);
    }
 
    cout << endl;
    bool isLoop = detectAndRemoveLoop(start);
 
    if(isLoop)
    {
        cout << "Linked List after removing loop \n";
        printList(start);
        cout << endl;
    }
    else
    cout << "No Loop Detected\n";
    return 0;
}
 
// This is code is contributed by bhanupsingh10
