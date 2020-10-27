#include<iostream>
using namespace std;
struct node{
int info;
struct node *next;
}*start;

class sll{
public:
    node *create_node(int);
    void insert_begin();
    void insert_pos();
    void insert_end();
    void delete_pos();
    void display();
    sll()
    {
        start = NULL;
    }
};

int main()
{
    int choice, nodes, element, position, i;
    sll sl;
    start = NULL;
    while(1)
    {
        cout<<endl<<"--------------------------------";
        cout<<endl<<"Operations on Singly Linked list";
        cout<<endl<<"--------------------------------";
        cout<<endl<<"1-Insert Node at beginning";
        cout<<endl<<"2-Insert Node at last";
        cout<<endl<<"3-Insert Node at position";
        cout<<endl<<"4-Delete particular Node";
        cout<<endl<<"5-Display Linked List";
        cout<<endl<<"6-Exit"<<endl;
        cout<<endl<<"Enter Your Choice:";
        cin>>choice;

        switch(choice)
        {
            case 1: cout<<"Inserting Node at beginning:"<<endl;
                    sl.insert_begin();
                    break;
            case 2: cout<<"Inserting Node at last:"<<endl;
                    sl.insert_end();
                    break;
            case 3: cout<<"Inserting Node at Position:"<<endl;
                    sl.insert_pos();
                    break;
            case 4: cout<<"Delete a particular Node:"<<endl;
                    sl.delete_pos();
                    break;
            case 5: cout<<"Display elements:"<<endl;
                    sl.display();
                    break;
            case 6: cout<<"Exiting....";
                    exit(1);
                    break;
            default: cout<<"Wrong choice";
        }
    }
}


node *sll::create_node(int value)
{
    struct node *temp, *s;
    temp = new(struct node);
    if(temp == NULL)
    {
        cout<<"Memory not allocated"<<endl;
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;
        return temp;
    }
}


void sll::insert_begin()
{
    int value;
    cout<<"Enter the value to be inserted:";
    cin>>value;
    struct node *temp, *p;
    temp = create_node(value);
    if(start == NULL)
    {
        start = temp;
        start->next = NULL;
    }
    else
    {
        p = start;
        start = temp;
        temp->next = p;
    }
    cout<<"Element inserted at beginning";
}


void sll::insert_end()
{
    int value;
    cout<<"Enter value to be inserted:";
    cin>>value;
    struct node *temp, *s;
    temp = create_node(value);
    s = start;
    while(s->next != NULL)
    {
        s = s->next;
    }
    temp->next = NULL;
    s->next = temp;
    cout<<"Element inserted at last";
}


void sll::insert_pos()
{
    int value, pos, counter=0;
    cout<<"Enter value to be inserted: ";
    cin>>value;
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    cout<<"Enter the position at which node to be inserted:";
    cin>>pos;
    int i;
    s = start;
    while(s != NULL)
    {
        s = s->next;
        counter++;
    }
    if(pos == 1)
    {
        if(start = NULL)
        {
            start = temp;
            start->next = NULL;
        }
        else
        {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if(pos>1 && pos<=counter)
    {
        s = start;
        for(i = 1;i<pos;i++)
        {
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;
        temp->next = s;
    }
    else
    {
        cout<<"Position out of Range";
    }
}


void sll::delete_pos()
{
    int pos, i, counter = 0;
    if(start==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value you want to delete:";
    cin>>pos;
    struct node *s, *ptr;
    s = start;
    if(pos==1)
    {
        start=s->next;
    }
    else
    {
        while(s!=NULL)
        {
            s=s->next;
            counter++;
        }
        if(pos>0 && pos<=counter)
        {
            s = start;
            for(i=1;i<pos;i++)
            {
                ptr=s;
                s=s->next;
            }
            ptr->next=s->next;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        free(s);
        cout<<"Element deleted"<<endl;
    }
}


void sll::display()
{
    struct node *temp;
    if(start==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    temp=start;
    cout<<"Elements of list are:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->info<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
