#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int value;
	struct	node *next;
} node;
node *create(){
	node *head,*p1,*p2;
	p1 = (node*)malloc(sizeof(node));
	if(p1 == NULL)
		return NULL;
	head = p1;
	printf("please input the value of linklist and the value 0 is terminate signal\n");
	scanf("%d",&p1->value);
	if(p1->value == 0)
		return NULL;
	p1->next = NULL;
	while(1){
		p2 = (node*)malloc(sizeof(node));
		if(p2 == NULL)
			return NULL;
		scanf("%d",&p2->value);
		if(p2->value == 0)
			break;
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;		
	}
	return head;

}
void print(node *p){
	while (1){
	if(p->next == NULL){
		printf("%d\n",p->value);
		break;
	}
	printf("%d->",p->value);
	p = p->next;
	}
}
node *change(node *p){
	node *q,*head1,*head2;
	head1 = p;
	head2 = q = p->next;
	while(p != NULL && p->next != NULL && q != NULL && q->next != NULL){
	p->next = q->next;
	p = q->next;
	q->next = p->next;
	q = p->next;
	}
	p->next = head2;
	return head1;
}
int main(){
	node *linklist,*p;
	p = create();
	print(p);
	p = change(p);
	print(p);
	free(p);		 
	return 0;
}
