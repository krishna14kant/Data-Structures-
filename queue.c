#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int size;
    int front, rear;
    int *arr;
}QUEUE;
void initQueue(QUEUE *q, int size)
{
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->arr = (int *)malloc(size * sizeof(int));
}
void store(QUEUE *q, int data)
{
    if(q->rear == q->size-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = data;
    }
}
int retreive(QUEUE *q)
{
    if(q->front == -1)
    {
        printf("Queue is empty\n");
        return (-1);
    }
    else
    {
        int item = q->arr[q->front];
        q->front++;
        return item;
    }
}
void display(QUEUE *q)
{
    if(q->rear == -1 || q->front > q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=q->front;i<=q->rear;i++)
        {
            printf("%d ",q->arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    QUEUE q1;
    initQueue(&q1, 5);
    store(&q1, 5); store(&q1, 15); store(&q1, 25); store(&q1, 35); store(&q1, 45); store(&q1, 55);
    display(&q1);
    printf("Deleted element : %d\n",retreive(&q1));
    display(&q1);
    printf("Deleted element : %d\n",retreive(&q1));
    printf("Deleted element : %d\n",retreive(&q1));
    printf("Deleted element : %d\n",retreive(&q1));
    display(&q1);
    printf("Deleted element : %d\n",retreive(&q1));
    display(&q1);
    return 0;
}
