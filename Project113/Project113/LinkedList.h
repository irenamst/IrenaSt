#pragma once

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct node {
	int data;
	struct node *next;
} Node;

////////////////////////////////////////

struct list {
	Node *head;
};

typedef struct list List;
/////////////////////

int Length(struct node* head);

void Push(struct node** headRef, int data);

struct node* BuildOneTwoThree();
///////////////

int Count(struct node* head, int searchFor);

int GetNth(struct node* head, int index);

void DeleteList(struct node** headRef);

int Pop(struct node** headRef);

void DestroyNode(node *headRef, node *node1);

void InsertNth(struct node** headRef, int index, int data);

void SortedInsert(struct node** headRef, struct node* newNode);

void InsertSort(struct node** headRef);

void Append(struct node** aRef, struct node** bRef);

void FrontBackSplit(struct node* source,
	struct node** frontRef, struct node** backRef);

void RemoveDuplicates(struct node* head);

void MoveNode(struct node** destRef, struct node** sourceRef);

void AlternatingSplit(struct node* source,
	struct node** aRef, struct node** bRef);

struct node* ShuffleMerge(struct node* a, struct node* b);

struct node* SortedMerge(struct node* a, struct node* b);

void MergeSort(struct node** headRef);

struct node* SortedIntersect(struct node* a, struct node* b);

void Reverse(struct node** headRef);

void RecursiveReverse(struct node** headRef);

#endif 


