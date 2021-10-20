#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
void display(struct node *q)
{
    while(q!=NULL)
    {
        printf("%d ",q->info);
        q=q->link;
    }
    printf("\n");
}
int count(struct node *q)
{
    int c=0;
    while(q!=NULL)
    {
        q=q->link;
        c++;
    }
    return c;
}
void append(struct node **q, int data)
{
    struct node *temp, *r;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info= data;
    temp->link=NULL;
    if(*q==NULL)
    {
        *q=temp;
    }
    else
    {
        r = *q;
        while(r->link!=NULL)
        {
            r=r->link;
        }
        r->link = temp;
    }
}
void insert(struct node **q, int pos, int data)
{
    int c=count(*q);
    if(pos==0)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = *q;
        *q=temp;
    }
    else if(pos>c)
    {
        printf("Invalid node no., Appending at end of list...\n");
        append(q,data);
    }
    else if(*q==NULL || pos ==c)
    {
        append(q,data);
    }
    else
    {
        struct node *temp,*r;
        temp=(struct node *)malloc(sizeof(struct node));
        r=*q;
        for(int i=1;i<=pos-1;i++)
        {
            r=r->link;
        }
        temp->info = data;
        temp->link = r->link;
        r->link = temp;
    }
}
void delete(struct node **q, int pos)
{
    int c=count(*q);
    if(pos == 0 || pos >c)
    {
        printf("Invalid node no.\n");
    }
    else if(q==NULL)
    {
        printf("Empty list :(\n");
    }
    else if(pos == 1)
    {
        struct node *temp;
        temp = *q;
        *q = temp->link;
        free(temp);
    }
    else
    {
        struct node *temp, *r;
        r=*q;
        for(int i=1;i<=pos-2;i++)
        {
            r= r->link;
        }
        temp= r->link;
        if(pos == c)
        {
            r->link = NULL;
        }
        else
        {
            r->link = temp->link;
        }
        free(temp);
    }
}
void delDuplicates(struct node **l1)
{
    struct node *r;
    r=*l1;
    int c=count(*l1), i=1, k=0;
    int positions[c-1];
    while(r!=NULL)
    {
        int current = r->info;
        struct node *s = r->link;
        for(int j=i+1;j<=c;j++)
        {
            if(s->info == current)
            {
                positions[k++] = j;
            }
            s=s->link;            
        }
        r = r->link;
        i++;
    }
    for(int i=k-1;i>=0;i--)
    {
        delete(l1, positions[i]);
    }
}
void reverse(struct node **q)
{
    struct node *prev , *current, *next;
    current = *q;
    prev = NULL;
    while(current!=NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *q = prev;
}
void concat(struct node **l1, struct node **l2)
{
    if(*l1==NULL)
    {
        *l1=*l2;
        return;
    }
    struct node *r = *l1;
    while(r->link!=NULL)
    {
        r=r->link;
    }
    r->link=*l2;
}
void sortList(struct node **q)
{
    struct node *r = *q;
    struct node *s = NULL;
    if(*q==NULL)
    return;
    else
    {
        while(r!=NULL)
        {
            s = r->link;
            while(s!=NULL)
            {
                if(r->info > s->info)
                {
                    int temp = r->info;
                    r->info = s->info;
                    s->info = temp;
                }
                s = s->link;
            }
            r = r->link;
        }
    }
}
int main()
{
    struct node *p1 = NULL, *p2 = NULL;
    append(&p1,10); append(&p1,20); append(&p1,30); append(&p1, 50); append(&p1, 60); append(&p1, 70);
    append(&p2, 31); append(&p2, 41); append(&p2, 51); append(&p2, 61); append(&p2, 71); append(&p2, 71);
    display(p1);
    display(p2);
    insert(&p1,3,40);
    delete(&p2,1);
    delDuplicates(&p2);
    display(p1);
    display(p2);
    concat(&p1,&p2);
    display(p1);
    sortList(&p1);
    display(p1);
    return 0;
}
