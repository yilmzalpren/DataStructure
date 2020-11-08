#include <stdio.h>

typedef struct Node {
	int age; 
	char c; 
	struct Node* next; 
	
	
}Node;


Node* createNode() {
	Node* root = NULL; 
	root = (Node*)malloc(sizeof(Node)); 
	int age; 
	char c; 
	printf("Please enter age: "); 
	scanf_s("%d", &age); 
	root->age = age; 
	printf("Please enter c: "); 
	while ((age = getchar()) != '\n' && age != EOF);
	scanf_s("%c", &c);
	root->c = c; 
	root->next = NULL; 
	return root; 
}

Node* createLinkedList(Node* root) { // hem create hem add..(add to last).
	if (root == NULL) {
		root = createNode(); 
		root->next = root; 
		return root; 
	}
	else {
		Node* iter = NULL; 
		iter = root; 
		while (iter->next != root) iter = iter->next; 
		iter->next = createNode(); 
		iter = iter->next; 
		iter->next = root; 
		return root; 
	}
}

Node* addSort(Node* root) { // it is imposabile to come NULL pointer...
	Node* temp = NULL;
	temp = createNode(); // temp ---> {age , c , *next= NULL}
	Node* iter = NULL;
	iter = root;
	if (temp->age <= root->age) {
		temp->next = root;
		while (iter->next != root) iter = iter->next; 
		iter->next = temp; 
		return temp; 
	}
	else {
		while (iter->next != root && (temp->age > iter->next->age))  iter = iter->next; 
		temp->next = iter->next; 
		iter->next = temp; 
		return root; 
	}
}

Node* addIndex(Node* root, int index) { // index -->  as   index -1 
	Node* temp = NULL;
	Node* iter = NULL; 
	iter = root; 

	if (index < 0) {
		printf("Invalid index(too low)\n"); 
		return root; 
	}
	
	else if (root == NULL) {
		if (index > 0) {
			printf("Empty linked list so you have to add in just first index \n");
			return root; 
		}
		else {
			temp = createNode(); 
			temp->next = temp; 
			return temp; 
		}
	}
	else if (index == 0) {
		temp = createNode();
		temp->next = root; 
		while (iter->next != root) iter = iter->next; 
		iter->next = temp; 
		return temp; 
	}
	else { // index > 0 
		int counter = 0; 
		for (int i = 0; i < index - 1 && iter->next != root ; ++i) {
			iter = iter->next;
			counter++; 
		}
		if (iter->next == root) {
			if (counter == (index - 1)) {
				temp = createNode(); 
				iter->next = temp; 
				temp->next = root; 
				return root; 
			}
			else {
				printf("Too much\n"); 
				return root; 
			}
		}
		else {
			temp = createNode(); 
			temp->next = iter->next; 
			iter->next = temp; 
			return root;
		}

	}
}
Node* push_back(Node* root) {
	Node* temp = NULL; 
	if (root == NULL) {
		temp = createNode(); 
		temp->next = temp; 
		return temp; 
	}
	else {
		Node* iter = NULL; 
		iter = root;
		while (iter->next != root) {
			iter = iter->next; 
		}
		temp = createNode(); 
		iter->next = temp; 
		temp->next = root; 
		return root; 
	}
}

Node* pop_back(Node* root) {
	if (root == NULL) {
		printf("Empty circular linked list\n") ; 
			return NULL; 
	}
	else {
		Node* iter = NULL; 
		iter = root; 
		if (iter->next == root) {
			free(root); 
			return NULL; 
		}
		else {
			while (iter->next->next != root) iter = iter->next; 
			free(iter->next); 
			iter->next = root; 
			return root; 
		}
	}
}

Node* deleteIndex(Node* root, int index) {
	if (index < 0) {
		printf("Too low index\n");
		return root; 
	}

	else if (root == NULL) {
		printf("This Linked List --> Empty \n"); 
		return NULL; 
	}
	else {
		Node* iter = NULL; 
		Node* temp = NULL; 
		iter = root; 

		if (index == 0) {
			if (iter->next == root) {
				free(root); 
				return NULL; 
			}
			else {
				temp = root; 
				while (iter->next != root) iter = iter->next;
				root = root->next; 
				iter->next = root; 
				free(temp); 
				return root; 

			}
		} // if(index==0) finish
		index--; 
		while (iter->next != root && index  > 0) {
			index--; 
			iter = iter->next; 
		}
		if (iter->next == root) {
			printf("too much index\n") ;
			return root; 
		}
		else {
			if (iter->next->next == root) {
				temp = iter->next; 
				iter->next = root; 
				free(temp); 
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

Node* deleteNumber(Node* root, int number) {
	if (root == NULL) {
		printf("Empty Linked List\n");
		return NULL;
	}

	else if (root->next == root) { // just one node 
		if (root->age == number) {
			free(root);
			return NULL;
		}
		else {
			printf("%d number dont exist in this linked list\n",number);
			return root;
		}
	}
	else { // at least 2 node 
		Node* iter = NULL; 
		Node* temp = NULL; 
		Node* keeper = NULL; 
		int counter = 0; 
		iter = root;
		if (number == root->age) { // at least 2 node and first node equall the number.
			counter++; 
			while (iter->next != root) {
				if (iter->next->age == number) {
					counter++; 
				}
				iter = iter->next; 
			}
			if (counter == 1) { // just first element equalls the number
				iter->next = root->next; 
				temp = root; 
				root = root->next; 
				free(temp); 
				return root; 

			}
			else { // counter >  1    at least 2 node equall the number(but first is obvious)
				printf("\n");
				iter = root; 
				while (counter > 0) {
					
					printf("%c---->%d\n", iter->c, iter->age); 
					iter = iter->next; 
					counter--; 
				}
				printf("Please choose one of them:\n");
				int choose; 
				scanf_s("%d", &choose); 
				choose -= 2; 
				if (choose < 0) { // it means first elemnt will be deleted
					while (iter->next != root) {
						iter = iter->next; 
					}
					temp = root;
					iter->next = root->next; 
					root = root->next; 
					free(temp); 
					return root; 

				}
				else { // it means first element will be not deleted.
					iter = root; 
					while (counter > 0) {
						iter = iter->next; 
						counter--; 
					}
					temp = iter->next; 
					iter->next = temp->next; 
					free(temp); 
					return root; 
				}
			}
		} 

		else { // first elemnt is not number and linked list has least 2 element
			while (iter->next != root) {
				if (iter->next->age == number) {
					counter++; 
					if (counter == 1) keeper = iter; 
				}

				iter = iter->next; 
			}
			if (counter == 0) { // it means that the number dont exist
				printf("The number dont exist in this linked list\n"); 
				return root; 
			}
			else { // counter-1 times go .. and find 
				if (counter == 1) {
					temp = keeper->next; 
					keeper->next = temp->next; 
					free(temp); 
					return root; 
				}
				else { // counter at least 2
					iter = keeper; 
					while (counter > 0) {
						printf("%c--->%d\n", iter->next->c, iter->next->age); 
						iter = iter->next; 
						counter--; 
					}
					printf("Please choose one of them for deleting:\n"); 
					int choose; 
					scanf_s("%d", &choose); 
					choose--; 
					while (choose > 0) {
						keeper = keeper->next;
						choose--; 
					}
					temp = keeper->next; 
					keeper->next = temp->next;
					free(temp); 
					return root; 
				}
			}
		}
	}
}

void printLinkedList(Node* root) {
	if (root == NULL) printf("Empty Linked List");  
	else {
		Node* iter = NULL; 
		iter = root; 
		do {
			printf("%c -----> %d\n", iter->c, iter->age);
			iter = iter->next; 
		} while (iter != root); 
	}
}

int main() {
	Node* root = NULL; 
	root = createNode(); 
	root->next = root; 

	for (int i = 0; i < 6; ++i) {
		root = addSort(root); 
	}
	
	printLinkedList(root); 

	int number; 
	for (int i = 0; i < 8; ++i) {
		printf("please choose number:"); 
		scanf_s("%d", &number); 
		root = deleteNumber(root, number); 
		printLinkedList(root);

	}


	return 0; 
}