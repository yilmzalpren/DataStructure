#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int age; 
	char c; 
	struct Node* next; 
	struct Node* prev;
}Node;

Node* addSort(Node* root) ; 
Node* createNode(); 
void printLinkedList(Node* root); 
Node* push_back(Node* root); 
Node* addIndex(Node* root, int index); 
Node* pop_back(Node* root); 
Node* deleteIndex(Node* root, int index); 
Node* deleteNumber(Node* root, int number); 

int main() {
	Node* root = NULL;
	int index; 
	
	for (int i = 0; i < 6; ++i) {

		root = addSort(root); 

	}
	printLinkedList(root);
	for (int i = 0; i < 9; ++i) {
		int number; 
		printf("Please select number what you wanna delete : "); 
		scanf_s("%d", &number); 
		root = deleteNumber(root, number); 
		printLinkedList(root); 

	}

	return 0; 
}

void printLinkedList(Node* root) {
	if (root == NULL) {
		printf("Empty doubly linked list\n");
		 
	}
	else {
		while (root != NULL) {
			printf("%c----->%d\n", root->c, root->age); 
			root = root->next; 
		}
	}
}

Node* createNode() {
	Node* temp = NULL; 
	temp = (Node*)malloc(sizeof(Node)); 
	temp->prev = NULL; 
	temp->next = NULL; 
	int age; 
	char c; 
	printf("Please enter age : "); 
	scanf_s("%d", &age); 
	temp->age = age; 
	printf("Please enter c : "); 
	while ((age = getchar()) != '\n' && age != EOF);
	scanf_s("%c", &c); 
	temp->c = c; 
	return temp; 
}

Node* push_back(Node* root) {
	if (root == NULL) {
		root = createNode(); 
		return root; 
	}
	else {
		Node* iter = NULL; 
		iter = root; 
		while (iter->next != NULL) iter = iter->next; 
		iter->next = createNode(); 
		iter->next->prev = iter;
		return root; 
	}
}

Node* addSort(Node* root) {
	if (root == NULL) {
		root = createNode(); 
		return root; 
	}
	else {
		Node* temp = NULL; 
		Node* iter = NULL; 
		iter = root; 
		temp = createNode();

		if (temp->age < iter->age) {
			root->prev = temp; 
			temp->next = root;
			root = root->prev; 
			return root;

		}
		else if (temp->age == iter->age) {
			int choose; 
			int count = 0; 
			while (iter != NULL && iter->age == temp->age) {
				count++; 
				printf("%c---->%d\n", iter->c, iter->age); 
				iter = iter->next;
			}
			printf("The node that you wanna add, enter  it will first or %dth", count + 1);
			scanf_s("%d", &choose);
			choose -= 2;
			if (choose < 0) {
				root->prev = temp; 
				temp->next = root; 
				root = root->prev; 
				return root; 
			}
			else {
				iter = root;
				while (choose > 0) {
					choose--; 
					iter = iter->next;
				}
				temp->next = iter->next;
				temp->prev = iter; 
				iter->next = temp; 
				if (temp->next) temp->next->prev = temp; 
				return root; 
			}

		}
		else {
			int counter = 0; 
			Node* keeper = NULL; 
			while (iter->next != NULL && iter->next->age <= temp->age) {
				if (iter->next->age == temp->age)counter++;
				if (counter == 1) keeper = iter;
				iter = iter->next;
			}
			if (counter == 0) {
				temp->next = iter->next;
				iter->next = temp; 
				temp->prev = iter; 
				if (temp->next) temp->next->prev = temp; 
				return root;
			}
			else {
				iter = keeper; 
				while (counter > 0) {
					printf("%c---->%d\n", keeper->next->c,keeper->next->age); 
					keeper = keeper->next; 
					counter--; 
				}
				int choose;
				printf("Please choose : ");
				scanf_s("%d", &choose);
				choose--;
				while (choose > 0) {
					iter = iter->next;
					choose--;
				}
				temp->next = iter->next;
				temp->prev = iter;
				iter->next = temp;
				if (temp->next) temp->next->prev = temp;
				return root;
			}

		}
	}


}

Node* addIndex(Node* root , int index) {
	if (root == NULL) {
		if (index == 0) {
			root = createNode(); 
			return root; 
		}
		else {
			printf("Invalid index\n") ; 
			return NULL; 
		}
	}
	else {
		if (index < 0) {
			printf("Invalid index\n");
			return root; 
		}
		else if(index==0) {
			root->prev = createNode(); 
			root->prev->next = root;
			root = root->prev; 
			return root;
		}
		else {
			Node* iter = NULL; 
			iter = root;
			index--; 
			while (index > 0 && iter->next != NULL) {
				index--; 
				iter = iter->next;
			}
			if (iter->next == NULL) {
				if (index == 0) {
					iter->next = createNode();
					iter->next->prev = iter; 
					return root; 
				}
				else {
					printf("Invalid Index\n"); 
					return root; 
				}
			}
			else {
				Node* temp = NULL; 
				temp = createNode(); 
				temp->next = iter->next;
				iter->next->prev = temp;
				temp->prev = iter;
				iter->next = temp; 
				return root; 
			}

		}
	}
}

Node* pop_back(Node* root) {
	if (root == NULL) {
		printf("The empty Linked List\n"); 
		return NULL; 
	}
	else {
		if (root->next == NULL) { // 1 node 
			free(root);
			return NULL; 
		}
		else {  // at least 2 node .
			Node* iter = NULL;
			iter = root; 
			while (iter->next->next != NULL) iter = iter->next;
			free(iter->next);
			iter->next = NULL; 
			return root; 
		}

	}
}
Node* deleteIndex(Node* root , int index) {
	if (root == NULL) {
		printf("Empty Linked List\n"); 
		return NULL; 
	}
	else {
		if (root->next == NULL) {
			if (index == 0) {
				free(root); 
				return NULL; 
			}
			else {
				printf("Invalid index\n"); 
				return root; 
			}
		}
		if (index < 0) {
			printf("Invalid index\n");
			return root; 
		}
		else if (index == 0) {
			Node* temp = NULL; 
			temp = root->next;
			temp->prev = NULL; 
			free(root); 
			return temp; 
		}
		else {
			index--; 
			Node* iter = NULL; 
			iter = root; 
			while (iter->next!=NULL && index > 0) {
				iter = iter->next;
				index--; 
			}
			if (iter->next == NULL) {
				printf("Invalid index\n");
				return root;
			}
			else {
				Node* temp = NULL;
				temp = iter->next;
				iter->next = temp->next;
				if (iter->next) iter->next->prev = iter;
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
	else {
		int counter = 0; 
		Node* keeper = NULL; 
		Node* iter = NULL; 
		iter = root; 
		if (number < root->age) {
			printf("The number don't exist in this program\n"); 
			return root;
		}
		else if (number == root->age) {
			counter++; 
			while (iter->next != NULL && iter->next->age == number) {
				iter = iter->next;
				counter++; 
			}
			if (counter == 1) {
				root = root->next;
				if (root) root->prev = NULL; 
				free(iter); 
				return root; 
			}
			else {
				iter = root; 
				while (counter > 0) {
					printf("%c------>%d\n", iter->c, iter->age);
					iter = iter->next; 
					counter--;
				}
				int choose; 
				printf("Please choose which index do you wanna delete : "); 
				scanf_s("%d", &choose); 
				choose--; 
				if (choose < 0) {
					printf("Invalid choose\n"); 
					return root; 
				}
				else if (choose == 0) {
					iter = root; 
					root = root->next;
					root->next->prev = NULL; 
					free(iter); 
					return root; 
				}
				else {
					choose--;
					iter = root; 
					while (iter->next != NULL && choose > 0) {
						iter = iter->next;
						choose--; 
					}
					if (iter->next == NULL) {
						printf("To much index \n"); 
						return root; 
					}
					else {
						Node* temp = NULL; 
						temp = iter->next;
						iter->next = temp->next;
						free(temp);
						if (iter->next) iter->next->prev = iter; 
						return root; 
					}
				}
			}
		}
		else {
			Node* keeper = NULL; 
			Node* temp = NULL; 
			while (iter != NULL && iter->age <= number) {
				if (iter->age == number) counter++; 
				if (counter == 1) keeper = iter; 
				iter = iter->next; 
			}
			if (counter == 0) {
				printf("Number can not exist\n"); 
				return root; 
			}
			else if (counter == 1 ) {
				temp = keeper; 
				keeper = keeper->prev; 
				keeper->next = temp->next; 
				if (keeper->next) keeper->next->prev = keeper; 
				free(temp); 
				return root; 
			}
			else {
				iter = keeper; 
				while (counter > 0) {
					printf("%c----->%d\n", iter->c, iter->age); 
					iter = iter->next; 
					counter--; 
				}
				printf("Please choose one of them do you wanna delete based 1 index : "); 
				int choose; 
				scanf_s("%d", &choose); 
				choose--; 
				if (choose < 0) {
					printf("Invalid index"); 
					return root; 
				}
				keeper = keeper->prev; 
				while( keeper->next != NULL && choose > 0) {
					keeper = keeper->next; 
					choose--; 
				}
				if (keeper->next == NULL) {
					printf("Too much index\n"); 
					return root; 
				}
				temp = keeper->next; 
				keeper->next = temp->next;
				free(temp); 
				if (keeper->next) keeper->next->prev = keeper; 
				return root; 
			}
		}
	}
}
