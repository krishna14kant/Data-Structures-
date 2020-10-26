#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void addatbeg(int );
void display();
struct node{
    int data;
    struct node *ptr;
};
struct node *s=NULL;
void main()
{
    addatbeg(100);
    addatbeg(90);
    addatebg(80);
    display();
    getch();
}
void addatbeg()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp-> data = num;
    if(s == num)
    {
        temp->ptr = num;
        s = temp;
    }
}
