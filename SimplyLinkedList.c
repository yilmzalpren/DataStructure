#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct Node {
	int age;
	char c;
	struct Node* next;

}Node;

void createNode(Node* iter, int number) {
	int k_age;
	char k_c;
	do {
		printf("Please enter age : ");
		scanf_s("%d", &k_age);

		iter->age = k_age;
		printf("Please enter c : ");
		while ((k_age = getchar()) != '\n' && k_age != EOF); // after that i wanna research it!!!
		scanf_s("%c", &k_c);

		iter->c = k_c;
		if (number != 1) {
			iter->next = (Node*)malloc(sizeof(Node));
			iter = iter->next;
		}
		else {

			iter->next = NULL;
		}
		number--;


	} while (number > 0);
}

void addNode(Node* iter, int number) {
	while (iter->next != NULL) iter = iter->next;
	for (int i = 0; i < number; ++i) {
		iter->next = (Node*)malloc(sizeof(Node));
		iter = iter->next;
		iter->next = NULL;
		int k_age;
		char k_c;
		printf("Please enter age : ");
		scanf_s("%d", &k_age);
		iter->age = k_age;
		printf("Please enter c : ");
		while ((k_age = getchar()) != '\n' && k_age != EOF); // after that i wanna research it!!!
		scanf_s("%c", &k_c);
		iter->c = k_c;
	}

}

Node* addIndex(Node* iter, int index) {

	Node* root = iter; 
	Node* temp = NULL;
	temp = (Node*)malloc(sizeof(Node));

	temp->age = 31;
	temp->c = 'y';

	if (index == 0) {

		temp->next = iter;
		return temp;

	}
	else {
		for (int i = 0; i < index -1 ; ++i) iter = iter->next; // if iter == NULL ----> return root and print that index overflow.
		temp->next = iter->next; 
		iter->next = temp; 
		return root; 
	}
}


void printNode(Node* iter) {
	while (iter != NULL) {
		printf("%c ---> %d\n", iter->c, iter->age);
		iter = iter->next;
	}
}
Node* initNode() {
	int k_age; 
	int age = 0; 
	char c = '\0'; 
	printf("Please enter age : "); 
	scanf_s("%d", &age);
	printf("Please enter c  : "); 
	while ((k_age = getchar()) != '\n' && k_age != EOF); // after that i wanna research it!!!
	scanf_s("%c", &c); 
	Node* temp = NULL; 
	temp = (Node*)malloc(sizeof(Node)); 
	temp->age = age; 
	temp->c = c;
	temp->next = NULL; 

	return temp;
}

Node* addSort(Node* iter) {
	if (iter == NULL) {
		iter = initNode(); 
		return iter; 
	}
	Node* root = NULL; 
	root = iter; 
	Node* temp = NULL; 
	temp = initNode();

	if (temp->age <= iter->age) {
		temp->next = iter; 
		return temp; 
	}


	else {
		while ((iter->next != NULL) && ( !(temp->age <= iter->next->age))) {

			iter = iter->next; 

		}
		temp->next = iter->next; 
		iter->next = temp; 
		return root; 
		
	}
}
Node* deleteIndex(Node * root , int choose) {
	Node* iter = NULL; 
	Node* temp = NULL; 

	if (root == NULL) return root;

	else if (choose == 0) {
		temp = root; 
		root = root->next; 
		free(temp);
		return root; 
	}
	else if(choose > 0) {
		iter = root; 
		for (int i = 0; i < choose - 1; ++i) {
			if (iter->next == NULL) {
				printf("Too much"); 
				return root; 
			}
			else {
				iter = iter->next; 
			}
		}
		if (iter->next == NULL) {
			printf("Too much"); 
			return root; 
		}
		else {
			temp = iter->next; 
			iter->next = temp->next; 
			free(temp);
			return root; 
		}
	}
	else {
		printf("Please enter from 1 to n\n"); 
		return root; 
	}

}
Node* deleteSort(Node* root, int number) {
	if (root == NULL) {
		printf("Empty LinkedList\n");
		return NULL;

	}
	else {
		Node* temp = NULL;
		Node* iter = NULL; 
		iter = root; 
		if (iter->age == number) {
			temp = iter; 
			iter = iter->next; 
			free(temp); 
			return iter;
		}
		else {
			while (iter->next != NULL && (iter->next->age!=number) ) {
				iter = iter->next; 
			}
			if (iter->next == NULL) {
				printf("Cannot find number:\n"); 
				return root;
			}
			else {
				temp = iter->next; 
				iter->next = temp->next; 
				free(temp); 
				return root;
			}
		}
	}
}

Node* reverseLinkedList(Node* i2) {

	if (i2 == NULL) return NULL; 
	else {
		Node* i1 = NULL;
		Node* i3 = NULL;
		i3 = i2->next; 
		while (i3 != NULL) {
			i2->next = i1; 
			i1 = i2; 
			i2 = i3; 
			i3 = i3->next; 
		}
		i2->next = i1;
		return i2; 
	}
}

int main() {
	int choose; 
	clock_t start = clock(), diff; 
	// ProcessIntenseFunction();

	Node* root = NULL; 
	
	for (int i = 0; i < 5; ++i) {
		root = addSort(root);

	}
	printNode(root); 
	//for (int i = 0; i < 10; ++i) {
	//	printf("\nPlease enter which  number do u wanna delete : ");
	//	scanf_s("%d", &choose);

	//	root = deleteSort(root, choose);
	//	printNode(root);
	//}
	root = reverseLinkedList(root); 
	printNode(root); 

	diff = clock() - start; 
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Time taken %d seconds %d milliseconds", msec / 1000, msec % 1000);

	return 0;
}

