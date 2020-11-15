#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"


void push(Node** mainRoot, Node node) {
	if (mainRoot[0] == NULL) {
		mainRoot[0] = (Node*)malloc(sizeof(Node));
		mainRoot[0]->age = node.age;
		mainRoot[0]->c = node.c;
		mainRoot[0]->next = NULL; 
	}
	else {
		Node* temp = NULL;
		temp = (Node*)malloc(sizeof(Node));
		temp->age = node.age;
		temp->c = node.c;
		temp->next = mainRoot[0];
		mainRoot[0] = temp; 
	}
}
Node top(Node* root) {
	if (root == NULL) {
		printf("Stack underflow");
		exit(1);
	}
	else {
		return root[0];
	}
}

Node pop(Node** mainRoot) {
	if (mainRoot[0] == NULL) {
		printf("Stack Underflow");
		exit(1);
	}
	else {
		Node* temp = NULL; 
		temp = mainRoot[0]; 
		mainRoot[0] = temp->next;
		Node robj; 
		robj = temp[0];
		free(temp);
		return robj; 
	}
}

void printStack(Node *root) {
	while (root != NULL) {
		printf("%c-------->%d\n", root->c, root->age);
		root = root->next;
	}
}


int main() {   // just debugging
	Node obj[5] = { {10,'a'},{11,'b'},{12,'c'},{13,'d'},{14,'e'} };
	Node* root = NULL; 
	for (int i = 0; i < 14; ++i) {
		push(&root, obj[i % 5]);
		printStack(root);
		printf("------------------------\n");
	}
	for (int i = 0; i < 15; ++i) {
		pop(&root);
		printStack(root);
		printf("-------------------------\n");
	}



}
//-----------------------------------------------------------------------
/*

#ifndef stack_ll
#define stack_ll
typedef struct Node {
	int age; 
	char c; 
	struct Node* next; 
}Node;
Node pop(Node**);
void push(Node**, Node);
void print(Node*); // i provide the user to debugging easily
Node top(Node*);


#endif // stack_ll





*/
