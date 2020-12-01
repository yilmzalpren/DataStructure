#include <stdio.h>
#include <stdlib.h>
#include "queue_ll.h"

void enqueue(Node **m_root , Node obj) {
	if (m_root[0] == NULL) {
		m_root[0] = (Node*)malloc(sizeof(Node));
		m_root[0][0] = obj; 
		m_root[0]->next = NULL; 
	}
	else {
		Node* iter = m_root[0];
		while (iter->next != NULL) iter = iter->next;
		iter->next = (Node*)malloc(sizeof(Node));
		iter->next[0] = obj;
		iter->next->next = NULL; 
	}
}

Node dequeue(Node** m_root) {
	if (m_root[0] == NULL) {
		printf("Queue Underflow");
		exit(1);
	}
	else {
		Node* temp = m_root[0];
		m_root[0] = m_root[0]->next; 
		Node r_obj = temp[0];
		free(temp);
		return r_obj;
	}
}

void print(Node* root) {
	while (root != NULL) {
		printf("%s--------------%d\n",root->name, root->x);
		root = root->next;
	}
}

int main() {    // debugging 

	Node* root = NULL; 
	Node obj[5] = { {12,"yilmaz"},{13,"alperne"},{14,"naber"},{15,"sansa"},{17,"elleam"} };
	for (int i = 0; i < 25; ++i) {
		enqueue(&root, obj[i % 5]);
		print(root);
		printf("---------------------------------------\n");
	}

	print(root);
	printf("---------------------------------------\n");
	for (int i = 0; i < 26; ++i) {
		dequeue(&root);
		print(root);
		printf("---------------------------------------\n");
	}
	return 0; 
}
//------------------------------------------
/*
#ifndef queue_ll
#define queue_ll

typedef struct Node {
	int x; 
	char* name; 
	struct Node* next; 
}Node;


#endif


*/
