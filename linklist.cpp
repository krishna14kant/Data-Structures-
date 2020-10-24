#include <stdlib.h>
#include <stdio.h>

struct linked_list{
	int data;
	struct linked_list* next;
};

typedef struct linked_list* node;

node head = NULL;

void AddNode(int value){
	node temp, p;
	temp = NULL;
	temp = (node)malloc(sizeof(struct linked_list));
	
	temp -> data = value;
	temp -> next = NULL;

	if(head == NULL){
		head = temp;
	}
	else{
		p = head;
		while(p-> next != NULL){
			p = p->next;
		}
	p -> next = temp;
	}
}
void BegNode(int value)
{
	node temp;
	temp = NULL;
	temp = (node)malloc(sizeof(struct linked_list));
	
	temp -> data = value;
	temp -> next = NULL;

	if(head == NULL){
		head = temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}
void printlist(){
	node p1;
	p1 = head;
   	printf("->");
	while(p1){
	printf("%d->", p1->data);
	p1 = p1 -> next;
	}
	
}

void insert(int pos, int val){
	node newptr = NULL;
	node ptr = head;
	int steps = 1;
	newptr = (node)malloc(sizeof(struct linked_list));
	newptr->data = val;
	while(steps < pos - 1){
		ptr = ptr -> next;
		steps++;
	}

	/*newptr -> next = ptr->next;
	ptr->next = newptr;
*/
	if(pos == 1){
		newptr-> next = head;
		head = newptr;
	}
	else{
		newptr-> next = ptr -> next;
		ptr -> next = newptr;
	}
}

void del_list(){
	node ptr;
	while(head != NULL){
		ptr = head;
		head = head -> next;
		free(ptr);	
	}
}
void del(int pos){
	node p = head, temp;
	if(pos == 1){
		temp = head;
		head = head -> next;
		free(temp);
	}
	else{
		for(int i=2; i<pos; i++){
				p = p -> next;
		}
			temp = p -> next;
			p -> next = temp -> next;
			free(temp);
	}
}
void print(node p)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		printf("%d->",p->data);
		print(p->next);
	}
}
void revprint(node p)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		print(p->next);
		printf("%d->",p->data);
		
	}
}
int main(){
	AddNode(2);
	AddNode(3);
	AddNode(4);
	AddNode(5);
	BegNode(12);
	print(head);
	printf("\n");
	revprint(head);
	insert(1,10);
	insert(3,7);
	printf("\n");
	printlist();
	del(3);
	printlist();
	printf("\n");
	del_list();
	printf("\n");
	printlist();

return 0;
}
