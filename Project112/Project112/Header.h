#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
	int data;
	int key;
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList()
{
	struct node *ptr = head;
	printf("\n[ ");

	while (ptr != NULL)             //start from the beginning
	{
		printf("(%d,%d)", ptr->key, ptr->data);
		ptr = ptr->next;
	}
	printf(" ]");
}

//insert link at the first location
void insertFirst(int key, int data) {

	struct node *link = (struct node*) malloc(sizeof(struct node));  //create a link

	link->key = key;
	link->data = data;

	link->next = head;   //point to the old first node
	head = link;         //point first to new first node
}

//delete first item
struct node* deleteFirst() {

	struct node *tempLink = head;   //save reference

	head = head->next;     //mark next first link as first
	return tempLink;       //return the deleted link
}

//is list empty
bool isEmpty() {
	return head == NULL;
}

int length() {
	int length = 0;

	struct node *current;

	for (current = head; current != NULL; current = current->next) {
		length++;
	}
	return length;
}

//find a link with given key
struct node* find(int key) {

	struct node *current = head;      //start from the first link

	if (head == NULL) {               //if list is empty
		return NULL;
	}


	while (current->key != key)        //navigate through list
	{

		if (current->next == NULL)      //if it is last node
		{
			return NULL;
		}
		else {

			current = current->next;     //go to next link
		}
	}
	return current;           //if data found, return the current Link
}

//delete a link with given key
struct node *delete1(int key) {

	struct node* current = head;   //start from the first link
	struct node* previous = NULL;

	if (head == NULL)      //if list is empty
	{
		return NULL;
	}

	//navigate through list
	while (current->key != key) {

		if (current->next == NULL)     //if it is last node
		{
			return NULL;
		}
		else {
			previous = current;          //store reference to current link
			current = current->next;     //move to next link
		}
	}

	if (current == head)        //found a match, update the link
	{
		head = head->next;     //change first to point to the next link
	}
	else {
		previous->next = current->next;   //bypass the current link
	}
	return current;
}

void sort() {
	int i, j, k, tempKey, tempData;
	struct node *current;
	struct node *next;

	int size = length();
	k = size;
	for (i = 0; i < size - 1; i++, k--) {
		current = head;
		next = head->next;
		for (j = 1; j < k; j++) {
			if (current->data > next->data) {
				tempData = current->data;
				current->data = next->data;
				next->data = tempData;

				tempKey = current->key;
				current->key = next->key;
				next->key = tempKey;
			}
			current = current->next;
			next = next->next;
		}
	}
}

void reverse(struct node** head_ref) {
	struct node* prev = NULL;
	struct node* current = *head_ref;
	struct node* next;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}