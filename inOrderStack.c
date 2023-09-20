
#include <stdio.h>
#define MAX 10		//Maximum stack value

typedef struct treeNode {		//defining the data type of the tree
	int data;
	struct Node* left;
	struct Node* right;
}treeNode;		

treeNode* stack[MAX];		//global tree pointer
int top = -1;		//global top of the stack

treeNode* makeRootNode(int data, treeNode* leftNode, treeNode* rightNode);
// a function to create a tree by returning a node adding data, and the child nodes
int isEmpty();		// returns 1 if the stack is empty, or 0
int isFull();		// returns 1 if the stack is full, or 0
void push(treeNode* node);		//a function to add a node to a stack
treeNode* pop();		//a function to print node and delete it
void inorderStack(treeNode* rootNode);		//Median traversal function through stack

void main() {
	treeNode* n6 = makeRootNode(25, NULL, NULL);
	treeNode* n5 = makeRootNode(16, NULL, NULL);
	treeNode* n4 = makeRootNode(1, NULL, NULL);
	treeNode* n3 = makeRootNode(20, n5, n6);
	treeNode* n2 = makeRootNode(4, n4, NULL);
	treeNode* n1 = makeRootNode(15, n2, n3); 		//making a tree

	printf("inorder by stack: \n");
	inorderStack(n1);		// printing tree using the root node n1 and median traversal
}

treeNode* makeRootNode(int data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode)); //Dynamic allocating the node
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;	
}

int isEmpty() {		
	if (top == -1) return 1;
	else return 0;		//return 1 if the stack is empty
}

int isFull() {		
	if (top == MAX - 1) return 1;
	else return 0;		//return 1 if the stack is full
}

void push(treeNode* node) {		
	if (isFull()) {		//end if the stack is full
		printf("stack is full\n");
		return;
	}
	else stack[++top] = node;		//add node to stack if there is a space
}
treeNode* pop() {		
	if (isEmpty()) {		//end if the stack is full
		printf("stack is empty\n");
		return;
	}
	else {
		printf("[%d] ", stack[top]->data);		
		return stack[top--];	// delete top node from the stack
	}
}


void inorderStack(treeNode* rootNode)		//Median traversal function through stack
{
	treeNode* stackNode = rootNode;
	while (1)
	{
		while (stackNode != NULL)//add left nodes to the stack untill the Null node
		{						//if the current node is Null, move to "if" and pop from the stack 
			push(stackNode);	//add to the current node stack
			stackNode = stackNode->left;	//move to the left node from the current node
		}
		//delete one by one if reaches to the Null node
		if (!isEmpty())		//if the stack is not empty
		{
			stackNode = pop();		//delete, revisit, and print the lastest pushed node
			stackNode = stackNode->right;		//move to the right node of the current node and repeat the above code
		}
		else
			break;		//end the function if the stack is empty
	}
}
