#include "stack_arr.h"
#include <stdlib.h>
#include <stdio.h>

void increaseByTwo(Stack_arr* obj) {
	Node* temp = NULL;
	obj->size *= 2; 
	temp = (Node*)malloc(sizeof(Node) * obj->size);
	for (int i = 0; i < obj->hill; ++i) {
		temp[i] = obj->keeper[i];
	}
	free(obj->keeper);
	obj->keeper = temp; 


}

void decraseByTwo(Stack_arr* obj) {
	Node* temp = NULL; 
	obj->size /= 2; 
	temp = (Node*)malloc(sizeof(Node) * obj->size);
	for (int i = 0; i < obj->hill; ++i) {
		temp[i] = obj->keeper[i];
	}
	free(obj->keeper);
	obj->keeper = temp; 
}


// THESE WAS SPECIAL FUNCTION THAT JUST I CAN SEE
//----------------------------------------------------------------------

Stack_arr* initStack_arr() {
	Stack_arr* obj = NULL; 
	obj = (Stack_arr *)malloc(sizeof(Stack_arr));
	obj->hill = 0; 
	obj->size = 2; 
	obj->keeper = NULL; 
	obj->keeper = (Node *)malloc(sizeof(Node)*2);
	return obj; 
}

Node pop(Stack_arr *obj) {
	if (obj->keeper == NULL) {
		printf("Invalid request\n");
		exit(1);
	}
	else if(obj->hill == 0) {
		printf("Stack underflow\n");
		exit(1);

	}
	else {
		if (obj->hill == obj->size / 4) {
			decraseByTwo(obj);
		}
		return obj->keeper[--obj->hill];
	}
}

void push(Node node, Stack_arr* obj) {
	if (obj->keeper == NULL) {
		printf("Your stack is initialized..\n");
		obj->keeper = (Node*)malloc(sizeof(Node) * 2);
	}
	if (obj->hill == obj->size) increaseByTwo(obj);

	obj->keeper[obj->hill++] = node; 

}

Node top(Stack_arr* obj) {
	if (obj->keeper == NULL) {
		printf("Invalid request\n");
		exit(1);
	}
	else if (obj->hill == 0) {
		printf("hill equals the zero\n");
		exit(1);
	}
	else{
		return obj->keeper[((obj->hill) - 1)];
	}
}

void print(Stack_arr* obj) {
	if (obj->keeper == NULL) {
		printf("Please create a stack structure\n");
		return;
	}
	printf("%d\n", obj->size);
	for (int i = 0; i < obj->hill; ++i) {
		
		printf("%c----------->%d\n", obj->keeper[i].c, obj->keeper[i].age);
	}
}
//----------------------------------------------------------------------------------------------------------
/* 

#ifndef stack_arr
#define stack_arr

typedef struct Node {
	int age; 
	char c;
}Node;

typedef struct Stack_arr {
	Node* keeper; 
	int hill;
	int size; 

}Stack_arr;
Stack_arr* initStack_arr();
Node pop(Stack_arr*);
void push(Node , Stack_arr*);
Node top(Stack_arr*);
void print(Stack_arr*);


#endif // stack_arr

*/
//----------------------------------------------------------------------------------------------------------------
/*
#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"



int main() {
	Stack_arr* structure1 = initStack_arr();
	Node obj[3] = { {31,'y'},{32,'a'},{33,'c'} };
	for (int i = 0; i < 21; ++i) {
		push(obj[i%3], structure1);
		print(structure1);
		printf("----------------\n");

	}
	Stack_arr* structure2 = NULL; 
	structure2 = initStack_arr();
	for (int i = 0; i < 21; ++i) {
		push(pop(structure1), structure2);
	}
	print(structure2);

}

*/
