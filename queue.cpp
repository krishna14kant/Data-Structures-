#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *link;   
};

struct node *rear=NULL;
struct node *front=NULL;

void enqueue(int data){
        struct node *temp = new node();
    if(!temp){
        cout<<"Memory full";
        return;
        }

    if(front==NULL && rear==NULL){
        temp->data=data;
        temp->link=NULL;
        front=temp;
        rear=front;
        return;
    }
    
    temp->data=data;
    rear->link=temp;
    rear=temp;
}

int dequeue(){
    if(front==NULL)
        cout<<"Queue empty";
    struct node *temp;
    temp=front;
    int d = temp->data;
    front=front->link;
    if(rear==NULL){
        rear=NULL;
    }    

    free(temp);

    return d;
}

void print(){
    if(front==NULL && rear==NULL)
        cout<<"Queue empty";
    struct node* temp = front;

    while (temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->link;
    }   
    
}
int main(){
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(10);
    int k = dequeue();
    cout<<"Dequeued ele is "<<k<<endl;
    print();
    return 0;
}
