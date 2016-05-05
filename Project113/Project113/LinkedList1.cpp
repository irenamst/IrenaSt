#include "LinkedList.h"
#include <stdlib.h>          
#include <stdio.h>
#include <assert.h>

int Length(struct node* head) {
	int count = 0;
	struct node* current = head;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return(count);
}

void Push(struct node** headRef, int newData) {
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}

struct node* BuildOneTwoThree() {
	struct node* head = NULL;
	Push(&head, 3);
	Push(&head, 2);
	Push(&head, 1);
	return(head);
}

//////////////////////////////////////////////
//1
int Count(struct node* head, int searchFor) {
	struct node* current;
	int count = 0;
	for (current = head; current != NULL; current = current->next) {
		if (current->data == searchFor) count++;
	}
	return count;
}

//2
int GetNth(struct node* head, int index) {
	struct node* current = head;
	int count = 0;
	while (current != NULL) {
		if (count == index)
			return(current->data);
		count++;
		current = current->next;
	}
	assert(0);
	return -1;
}

//3
void DeleteList(struct node** headRef) {
	struct node* current = *headRef;
	struct node* next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	*headRef = NULL;
}

//4
int Pop(struct node** headRef) {
	struct node* head;
	int result;
	head = *headRef;
	assert(head != NULL);
	result = head->data;
	*headRef = head->next;
	free(head);
	return(result);
}

//5
void DestroyNode(node *headRef, node *node1) {
		if (!headRef || !headRef->next)
			return;
		if (headRef == node1){
			node1 = headRef->next;
			headRef->data = node1->data;
		}
		while (headRef->next && headRef->next != node1){
			headRef = headRef->next;
		}
		if (headRef->next == node1){
			headRef->next = node1->next;
			delete node1;
		}
		return;
}

//6
void InsertNth(struct node** headRef, int index, int data) {
	
	if (index == 0) Push(headRef, data);
	else {
		struct node* current = *headRef;
		int i;
		for (i = 0; i < index - 1; i++) {
			assert(current != NULL);
			current = current->next;
		}
		assert(current != NULL);
		Push(&(current->next), data);
	}
}

//7
void SortedInsert(struct node** headRef, struct node* newNode) {
	struct node temp;
	struct node* current = &temp;
	temp.next = *headRef;
	while (current->next != NULL && current->next->data < newNode->data) {
		current = current->next;
	}
	newNode->next = current->next;
	current->next = newNode;
	*headRef = temp.next;
}

//8
void InsertSort(struct node** headRef) {
	struct node* result = NULL;
	struct node* current = *headRef;
	struct node* next;
	while (current != NULL) {
		next = current->next;
		SortedInsert(&result, current);
		current = next;
	}
	*headRef = result;
}

//9
void Append(struct node** aRef, struct node** bRef) {
	struct node* current;
	if (*aRef == NULL) {
		*aRef = *bRef;
	}
	else {
		current = *aRef;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = *bRef;
	}
	*bRef = NULL;
}

//10
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef) {
	struct node* fast;
	struct node* slow;
	if (source == NULL || source->next == NULL) {
		*frontRef = source;
		*backRef = NULL;
	}
	else {
		slow = source;
		fast = source->next;
		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				slow = slow->next;
				fast = fast->next;
			}
		}
		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
}

//11
void RemoveDuplicates(struct node* head) {
	struct node* current = head;
	if (current == NULL) return;
	while (current->next != NULL) {
		if (current->data == current->next->data) {
			struct node* nextNext = current->next->next;
			free(current->next);
			current->next = nextNext;
		}
		else {
			current = current->next;	
		}
	}
}

//12
void MoveNode(struct node** destRef, struct node** sourceRef) {
	struct node* newNode = *sourceRef;
	assert(newNode != NULL);
	*sourceRef = newNode->next;
	newNode->next = *destRef;
	*destRef = newNode;
}

//13
void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef) {
	struct node* a = NULL;
	struct node* b = NULL;
	struct node* current = source;
	while (current != NULL) {
		MoveNode(&a, &current);
		if (current != NULL) {
			MoveNode(&b, &current);
		}
	}
	*aRef = a;
	*bRef = b;
}

//14
struct node* ShuffleMerge(struct node* a, struct node* b) {
	struct node* result;
	struct node* recur;
	if (a == NULL) return(b);
	else if (b == NULL) return(a);
	else {
		recur = ShuffleMerge(a->next, b->next);
		result = a;
		a->next = b;
		b->next = recur;
		return(result);
	}
}

//15
struct node* SortedMerge(struct node* a, struct node* b) {
	struct node* result = NULL;
	
	if (a == NULL) return(b);
	else if (b == NULL) return(a);
	
	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}

//16
void MergeSort(struct node** headRef) {
	struct node* head = *headRef;
	struct node* a;
	struct node* b;
	if ((head == NULL) || (head->next == NULL)) return;
	FrontBackSplit(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*headRef = SortedMerge(a, b);
}

//17
struct node* SortedIntersect(struct node* a, struct node* b) {
	struct node temp;
	struct node* tail = &temp;
	temp.next = NULL;
	while (a != NULL && b != NULL) {
		if (a->data == b->data) {
			Push((&tail->next), a->data);
			tail = tail->next;
			a = a->next;
			b = b->next;
		}
		else if (a->data < b->data) {
			a = a->next;
		}
		else {
			b = b->next;
		}
	}
	return(temp.next);
}

//18
void Reverse(struct node** headRef) {
	struct node* result = NULL;
	struct node* current = *headRef;
	struct node* next;
	while (current != NULL) {
		next = current->next;
		current->next = result;
		result = current;
		current = next;
	}
	*headRef = result;
}

//19
void RecursiveReverse(struct node** headRef) {
	struct node* first;
	struct node* rest;
	if (*headRef == NULL) return;	
	first = *headRef;
	rest = first->next;
	if (rest == NULL) return;
	RecursiveReverse(&rest);
	first->next->next = first;
	first->next = NULL;
	*headRef = rest;
}



