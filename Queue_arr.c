#include <stdio.h>
#include <stdlib.h>
#include "queue_arr.h"    // in the below comment section

Queue_arr* init() {
	Queue_arr* temp = NULL; 
	temp = (Queue_arr*)malloc(sizeof(Queue_arr));
	temp->head = 0; 
	temp->tail = 0;
	temp->htour = 0;
	temp->ttour = 0;
	temp->keeper = (Node*)malloc(sizeof(Node) * 2);
	temp->size = 2; 
	return temp; 

}

void increaseByTwo(Queue_arr* q) {
	Node* temp = NULL; 
	temp = (Node*)malloc(sizeof(Node) * (q->size) * 2);
	for (int i = 0; i < q->size; ++i) {
		temp[i] = q->keeper[((q->head) + i) % q->size];
	}
	free(q->keeper);
	q->keeper = temp; 
	q->head = 0;
	q->htour = 0;
	q->ttour = 0; 
	q->tail = q->size;
	q->size *= 2;
}
void decraseByTwo(Queue_arr* q) {
	Node* temp = NULL; 
	temp = (Node*)malloc(sizeof(Node) * (q->size / 2));
	int iter = (q->ttour * q->size) + q->tail - (q->htour * q->size + q->head);
	for (int i = 0; i < iter; ++i) {
		temp[i] = q->keeper[(q->head + i) % q->size];
	}
	free(q->keeper);
	q->keeper = temp;
	q->head = 0;
	q->tail = iter; 
	q->htour = 0; 
	q->ttour = 0; 
	q->size /= 2; 

}

Node dequeu(Queue_arr* q) {
	if (q->head == q->tail) {
		if (q->htour == q->ttour) {
			printf("Stack underflow\n");
			exit(1);
		}
	}
	int check = (q->ttour * q->size) + q->tail - (q->htour * q->size + q->head);
	if (check == q->size / 4) {
		decraseByTwo(q);
	}

	q->head++;
	if (q->head == q->size) {
		q->head = 0;
		q->htour += 1;
		return q->keeper[q->size - 1];
	}
	return q->keeper[q->head - 1];

}

void enqueu(Queue_arr* q, Node obj) {
	if (q->head == q->tail) {
		if (q->htour == q->ttour) {
			q->keeper[q->tail++] = obj; 
			if (q->tail == q->size) {
				q->tail = 0; 
				q->ttour++; 
				 
			}
			return;
		}
		else {
			increaseByTwo(q);
			q->keeper[q->tail++] = obj;
			if (q->tail == q->size) {
				q->tail = 0; 
				q->ttour++;
			}
			return; 
			// 1 -> 2 lik bir sey olmasin.
		}
	}
	else {
		q->keeper[q->tail++] = obj; 
		if (q->tail == q->size) {
			q->tail = 0; 
			q->ttour++;
		}
		return; 

	}
}

void print(Queue_arr* q) {
	int check = (q->ttour * q->size) + q->tail - (q->htour * q->size + q->head);
	printf("%d\n", q->size);
	for (int i = 0; i < check; ++i) {
		printf("%c--------->%d\n", q->keeper[(q->head + i) % q->size].c, q->keeper[(q->head + i) % q->size].age);
	}

}


int main() { // debugging 
	Queue_arr* p = init();
	Node obj = { 12,'y' };
	for (int i = 0; i < 50; ++i) {
		enqueu(p,obj);
		print(p);
		printf("-----------------------\n");
	}
	for (int i = 0; i < 51; ++i) {
		dequeu(p);
		print(p);
		printf("------------------------\n");
	}

	return 0; 
}
//----------------------------------------------------------------------------------
/*

#ifndef  queue_arr
#define queue_arr

typedef struct Node {
	int age;
	char c;
}Node;

typedef struct Queue_arr {
	Node* keeper; 
	int head, tail, size; 
	int htour; 
	int ttour;

}Queue_arr;


#endif // ! queue_arr


*/
