#include <stdio.h>
#include <stdlib.h>
#include "queue_ll.h"
// O(1) time complexity
QueueElement init() {
	QueueElement robj = {NULL,NULL};
	return robj;
}

void enqueue(QueueElement* m_root, Node obj) {
	if (m_root->tail == NULL) {
		m_root->tail = (Node*)malloc(sizeof(Node));
		m_root->tail[0] = obj; 
		m_root->tail->next = NULL; 
		m_root->head = m_root->tail;
	}
	else {
		m_root->tail->next = (Node*)malloc(sizeof(Node));
		m_root->tail = m_root->tail->next;
		m_root->tail[0] = obj;
		m_root->tail->next = NULL; 

	}
}

Node dequeue(QueueElement* m_root) {
	if (m_root->head == NULL) {
		printf("Queue underflow");
		exit(1);
	}
	else if (m_root->head == m_root->tail) {
		Node robj = m_root->head[0];
		free(m_root->head);
		m_root->head = m_root->tail = NULL; 
		return robj; 
	}
	else {
		Node robj = m_root->head[0];
		Node* temp = m_root->head; 
		m_root->head = m_root->head->next;
		free(temp);
		return robj; 
	}
}
void print(QueueElement root) {
	while (root.head != NULL) {
		printf("%s--------------%d\n", root.head->name, root.head->x);
		root.head = root.head->next;
	}
	printf("-----------------------------------------------------\n");
}

int main() { // debugging
	Node obj[5] = { {10,"yilmaz"},{11,"alperen"},{12,"asd"},{13,"brs"},{14,"falcao"} };
	QueueElement root = init();

	for (int i = 0; i < 6; ++i) {
		enqueue(&root, obj[i % 5]);
		print(root);
		
	}
	for (int i = 0; i < 7; ++i) {
		dequeue(&root);
		print(root);
	}
}
//----------------------------------------------------
/*
#ifndef queue_ll
#define queue_ll

typedef struct Node {
	int x; 
	char* name; 
	struct Node* next; 
}Node;

typedef struct QueueElement {
	Node* head; 
	Node* tail; 

}QueueElement;


#endif

*/
