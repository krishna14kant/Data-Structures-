//Using array
#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int size;
    int *arr;
    int top;
}STACK;

void initstack(STACK *s, int size)
{
    s->top = -1;
    s->size = size;
    s->arr = (int *)malloc(size * sizeof(int));
}
void push(STACK *s, int data)
{
    if(s->top == s->size-1)
    {
        printf("Stack Overflow !\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;
}
int pop(STACK *s)
{
    int data;
    if(s->top == -1)
    {
        printf("Stack Underflow !\n");
        return NULL;
    }
    data = s->arr[s->top];
    s->top--;
    return data;
}
void display(STACK *s)
{
    for(int i=0;i<s->top+1;i++)
    {
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}
int main()
{
    STACK s1;
    initstack(&s1, 5);
    push(&s1, 5); push(&s1, 10); push(&s1, 20); push(&s1, 30); push(&s1, 40);
    display(&s1);
    printf("Popped element: %d\n",pop(&s1));
    display(&s1);
    return 0;
}



//Using linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int value;
    struct stack *next;
}STACK;
void push(STACK **top, int data)
{
    STACK *temp = (STACK *)malloc(sizeof(STACK));
    temp->value = data;
    temp->next = *top;
    *top = temp;
}
int pop(STACK **top)
{
    if(*top == NULL)
    {
        printf("Stack Underflow !\n");
        return NULL;
    }
    STACK *temp = *top;
    int item = temp->value;
    *top = (*top)->next;
    free(temp);
    return item;
}
void display(STACK *top)
{
    if(top == NULL)
    printf("Empty Stack !!");
    else 
    {
        while(top!=NULL)
        {
            printf("%d ",top->value);
            top = top->next;
        }
    }
    printf("\n");
}
int main()
{
    STACK *s1 = NULL;
    display(s1);
    push(&s1, 5); push(&s1, 10); push(&s1, 20); push(&s1, 30); push(&s1, 40);
    display(s1);
    printf("Popped element: %d\n",pop(&s1));
    display(s1);
    return 0;
}
