#include <stdlib.h>
#include <stdio.h>
#include "binarySTree.h"
int height = -1;    // this two variable should be in the tree element if it requrested.
int checkHeight = 0; 

void findHeight(Node *root) {
	if (root == NULL) {
		if (height > checkHeight) checkHeight = height;
		height++;
		return;
	}
	else {
		height++;
		findHeight(root->left);
		height--;
		findHeight(root->right);
		height--;
	}
}

Node* insertIter(Node* root, Node obj) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->age = obj.age;
		root->c = obj.c;
		root->left = NULL; 
		root->right = NULL; 
		root->parent = NULL; 
		return root; 
	}
	else {
		_Bool where; // 0 means left / 1 means right.
		Node* iter = NULL; 
		Node* parent = NULL; 
		iter = root; 
		while (1) {
			if(iter->age > obj.age) {
				if (iter->left == NULL) {
					where = 0; 
					break; 
				}
				else {
					iter = iter->left;
					continue;
				}

			}
			else { // obj-age >= iter->age
				if (iter->right == NULL) {
					where = 1; 
					break; 
				}
				else {
					iter = iter->right;
					continue;
				}


			}
		} // end while(1)
		if (where == 0) {
			iter->left = (Node*)malloc(sizeof(Node));
			iter->left->left = NULL; 
			iter->left->right = NULL; 
			iter->left->parent = iter;
			iter->left->age = obj.age;
			iter->left->c = obj.c;
		}
		else {
			iter->right = (Node*)malloc(sizeof(Node));
			iter->right->left = NULL;
			iter->right->right = NULL;
			iter->right->parent = iter;
			iter->right->age = obj.age;
			iter->right->c = obj.c;

		}
		return root; 


	}

}

Node* insert(Node * root,Node obj,Node * parent) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->age = obj.age;
		root->c = obj.c;
		root->left = NULL; 
		root->right = NULL; 
		root->parent = parent; 
		return root; 
	}
	else {
		if (obj.age < root->age) {
			root->left=insert(root->left, obj,root);
		}
		else {
			root->right=insert(root->right, obj,root);
		}
		return root; 
	}
}
void ldr(Node* root) {
	if (root == NULL) return; 
	ldr(root->left);
	printf("%c------------->%d\n", root->c, root->age);
	ldr(root->right);
}

void dlr(Node* root) {
	if (root == NULL)return ; 
	printf("%c------------->%d\n", root->c, root->age);
	dlr(root->left);
	dlr(root->right);
}

void rdl(Node* root) {
	if (root == NULL) return; 
	rdl(root->right);
	printf("%c------------------->%d\n", root->c, root->age);
	rdl(root->left);
}

Node search(Node* root, int key) {
	Node temp;
	/*
	* This very old c, What is that ?
	*The return from the function will be the reuslt of the last evalution in the function.
	*
	*

	*/
	if (root == NULL) {
		printf("Key value not in this tree\n");
		exit(1);
	}
	else if (root->age == key) {
		printf("The key value is fonded  : %d", root->age);
		return root[0]; // and this will be last evalution.
	}
	else if (root->age > key) {
		temp = search(root->left,key);
	}
	else if (root->age < key) {
		temp = search(root->right,key);
	}
	return temp; 
}

void findMax(Node * root) {
	if (root == NULL) {
		printf("Empty tree\n");
		return; 
	}
	else {
		if (root->right == NULL) {
			printf("\n");
			printf("the max value that searched is ---> %d\n", root->age);
			return; 
		}
		else {
			findMax(root->right);
			return; 
		}
	}
}

void findMin(Node *root) {
	if (root == NULL) {
		printf("Empty tree");
		return; 
	}
	else {
		if (root->left == NULL) {
			printf("The min value that searched is ---->%d\n", root->age);
		}
		else {
			findMin(root->left);
		}
	}
}

void deleteNode(Node** m_root, Node obj) {
	Node* iter = NULL;
	iter = m_root[0];
	while (iter != NULL) {
		if (iter->age == obj.age) {
			break; 
		}
		else if (iter->age > obj.age) {
			iter = iter->left;
		}
		else {
			iter = iter->right;
		}
	}

	if (iter == NULL) {
		if (m_root[0] == NULL) {
			printf("underflow condition"); 
			exit(1);
		}
		else {
			printf("This node don't exist in this tree"); 
			return; 
		}
	}
	else {   // Everything will be here xd
		if (iter->left == NULL && iter->right == NULL) {   // NULL -----Node ------ NULL 
			if (iter->parent == NULL) {   // If this is first node
				free(iter);
				m_root[0] = NULL; 
				return; 
			}
			else {						// this is not first node
				if (iter->parent->right == iter) {
					iter->parent->right = NULL; 
					free(iter);
					return; 
				}
				else {
					iter->parent->left = NULL; 
					free(iter);
					return; 
				}
			}
		}
		//-----------------------------------------------------
		else if (iter->left == NULL) {
			if (iter->parent == NULL) {			//this is a first node
				m_root[0] = iter->right;
				iter->right->parent = NULL; 
				free(iter);
				return; 
			}	
			else {								// this is not first node
				if (iter->parent->right == iter) {
					iter->parent->right = iter->right;
					iter->right->parent = iter->parent;
					free(iter);
					return; 
				}
				else {
					iter->parent->left = iter->right;
					iter->right->parent = iter->parent;
					free(iter);
					return; 
				}
			}

		}
		//-----------------------------------------------------
		else if (iter->right == NULL) {
			if (iter->parent == NULL) {			// first node
				m_root[0] = iter->left;
				iter->left->parent = NULL; 
				free(iter);
				return; 
			}
			else {									// it is not first node
				if (iter->parent->right == iter) {
					iter->parent->right = iter->left;
					iter->left->parent = iter->parent;
					free(iter);
					return; 
				}
				else {
					iter->parent->left = iter->left;
					iter->left->parent = iter->parent;
					free(iter);
					return; 
				}

			}
		}
		//-----------------------------------------------------
		else {
			Node* iter2 = iter;
			iter2 = iter2->left;
			while (iter2->right != NULL)iter2 = iter2->right;
			Node temp; temp.age = iter->age; temp.c = iter->c;
			iter->age = iter2->age;
			iter->c = iter2->c;
			iter2->age = temp.age;
			iter2->c = temp.c;
			deleteNode(&(iter->left), obj);
			return; 
			

		}
	}
}



int main() { // debugging
	Node* root = NULL;
	Node ojb1 = { 15,'y',NULL,NULL,NULL };
	Node ojb2 = { 4,'a',NULL,NULL,NULL };
	Node ojb3 = { 22,'b',NULL,NULL,NULL };
	Node ojb4 = { 311,'c',NULL,NULL,NULL };
	Node ojb5 = { 31,'h',NULL,NULL,NULL };
	Node ojb6 = { 23,'j',NULL,NULL,NULL };
	Node ojb7 = { 59,'k',NULL,NULL,NULL };
	Node ojb8 = { 42,'t',NULL,NULL,NULL };
	Node ojb9 = { 1,'x',NULL,NULL,NULL }; //***********************
	Node ojb12 = { 2,'t',NULL,NULL,NULL };
	Node ojb13  = { -42,'t',NULL,NULL,NULL };
	Node ojb14 = { 0,'t',NULL,NULL,NULL };
	Node ojb15 = { -23,'t',NULL,NULL,NULL };
	Node ojb16 = { 6,'t',NULL,NULL,NULL };
	Node obj17 = { 16,'c',NULL,NULL,NULL };


	//root= insert(root, ojb1,NULL);
	//root = insert(root, ojb2,NULL);
	//root = insert(root, ojb3,NULL);
	//root = insert(root, ojb4,NULL);
	//root = insert(root, ojb5, NULL);
	//root = insert(root, ojb6, NULL);
	//root = insert(root, ojb7, NULL);
	//root = insert(root, ojb8, NULL);
	//root = insert(root, ojb9, NULL);
	root = insertIter(root, ojb1);
	root = insertIter(root, ojb2);
	root = insertIter(root, ojb3);
	root = insertIter(root, ojb4);
	root = insertIter(root, ojb5);
	root = insertIter(root, ojb6);
	root = insertIter(root, ojb7);
	root = insertIter(root, ojb8);
	root = insertIter(root, ojb9);
	Node obj11 = { -1,'a',NULL,NULL,NULL };
	root = insertIter(root, obj11);
	root = insertIter(root, ojb12);
	root = insertIter(root, ojb13);
	root = insertIter(root, ojb14);
	root = insertIter(root, ojb15);
	root = insertIter(root, ojb16);
	root = insertIter(root, obj17);


	//----------------------------------------------------------------
	dlr(root);
	printf("----------------------------\n");
	ldr(root);
	printf("----------------------------\n");

	deleteNode(&root, ojb1);
	dlr(root);
	printf("----------------------------\n");

	deleteNode(&root, ojb16);
	dlr(root);
	printf("----------------------------\n");
	deleteNode(&root, ojb2);
	dlr(root);
	printf("----------------------------\n");
	deleteNode(&root, ojb12);
	dlr(root);
	printf("----------------------------\n");
	deleteNode(&root, ojb9);
	dlr(root);
	printf("----------------------------\n");
	deleteNode(&root, ojb14);
	dlr(root);
	printf("----------------------------\n");
	deleteNode(&root, obj11);
	dlr(root);
	printf("----------------------------\n");
	deleteNode(&root, ojb15);
	dlr(root);
	printf("----------------------------\n");
	deleteNode(&root, ojb13);
	dlr(root);
	printf("----------------------------\n");

	//// findHeight(root);
	////printf("%d", checkHeight);
	//ldr(root);
	//printf("-------------------------------\n");
	////dlr(root);
	////printf("-------------------------------\n");

	//rdl(root);
	//system("cls");
	//Node yilmaz = search(root, 23);
	//findMax(root);
	//findMin(root);

	return 0; 
}
/*
#ifndef binarySTree
#define binarySTree

typedef struct Node {
	int age; 
	char c; 
	struct Node* left;
	struct Node* right;
	struct Node* parent;


}Node;


#endif // !binarySTree




*/
