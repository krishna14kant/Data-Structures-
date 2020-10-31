#include<stdio.h>
#include<conio.h>
typedef struct CLL
{
	int data;
	struct CLL *next;

}node;
node *create(node *);
void disp(node *);
node *insert(node *);
node *last=NULL;   // global
void main()
{
	node *a=NULL; // assigniing NULL is imp.
	clrscr();
	a=create(a);
	printf("\nThe circular ll\n");
	disp(a);
	a=insert(a);
	printf("\nAfter insertion\n");
	disp(a);
	getch();
}
node *create(node *a)
{
	int d;
	node *root=a;  // *root=NULL
	printf("Enter the data (-999 to exit) :");
	scanf("%d",&d);
	while(d!=-999)
	{
		if(a==NULL)
		{
			a=(node *)malloc(sizeof(node));
			a->data=d;
			root=a;
		}
		else
		{
			a->next=(node *)malloc(sizeof(node));
			a=a->next;
			a->data=d;
		}

		printf("Enter the data (-999 to exit) :");  // if u do not write this line, while will be infinite.
		scanf("%d",&d);
	}
	last=a;
	last->next=root; // a->next=root . Circular effect
	return root;
}
void disp(node *a)
{
	node *root=a;
	if(a==NULL)
	{
		printf("\nThe circular ll is empty!");
		return;
	}

	do
	{
		printf("%d ",a->data);  // 1 2 3 4
		a=a->next;

	}while(a!=root);
	printf("%d ",a->data);  // 1

}
node *insert(node *a)
{
	int ch,i=0,pos;
	node *root=a,*nnode=NULL,*b=NULL;
	nnode=(node*)malloc(sizeof(node));
	printf("\n\nEnter the data:");
	scanf("%d",&nnode->data);
	printf("Enter 1 to insert in beg\n2 in bet\n3 at the end\nUr choice:");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			nnode->next=root;
			root=nnode;          // line 1
			last->next=root;     // line 2
			break;
		case 2:  // exactly as of Singl linked list
			printf("\nEnter the pos:");
			scanf("%d",&pos);

			while(i<pos-1)
			{
				b=a;
				a=a->next;
				i++;  // if not then while will be infinite
			}
			b->next=nnode;
			nnode->next=a;
			break;
		case 3:
			last->next=nnode;
			last=nnode;
			last->next=root;
			break;
	}


	return root;

}
