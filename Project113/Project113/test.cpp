#include "HeaderLinkedList.h"
#include <stdlib.h>
#include <stdio.h>
void PopTest();
void InsertNthTest();
void MoveNodeTest();
void display(struct node*);
void MoveNodeTest();
void ReverseTest();
int main()
{
	struct node* head;
	int len;
	head = BuildOneTwoThree();
	ReverseTest();
	display(head);
	Push(&head, 13);
	Push(&(head->next), 42);
	len = Length(head);
	printf("%d\n", len);
	int m = Count(head, 2);
	display(head);
	DeleteList(&head); 
	struct node* myList = BuildOneTwoThree(); 
	int lastNode = GetNth(myList, 2); 
	InsertNthTest();
	PopTest();
	display(head);
	MoveNodeTest();
	getchar();
	return 0;
}
void display(struct node* head)
{
	struct node *temp;
	temp = head;
	while (temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	} printf("\n");
}
void PopTest() {
	struct node* head = BuildOneTwoThree(); 
	int a = Pop(&head); 
	int b = Pop(&head); 
	int c = Pop(&head); 
	int len = Length(head); 
	printf("%d\n", len);
}
void InsertNthTest() {
	struct node* head = NULL; 
	InsertNth(&head, 0, 13); 
	InsertNth(&head, 1, 42);
	InsertNth(&head, 1, 5); 
	int len = Length(head);
	printf("%d\n", len);
	DeleteList(&head); 
	len = Length(head);
	printf("%d\n", len);
}
void MoveNodeTest() {
	struct node* a = BuildOneTwoThree(); 
	struct node* b = BuildOneTwoThree();
	display(a);
	display(b);
	MoveNode(&a, &b);
	display(a);
	display(b);
}
void ReverseTest() {
	struct node* head;
	head = BuildOneTwoThree();
	display(head);
	Reverse(&head);
	display(head);
	
	DeleteList(&head); 
}
