#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node//creating a node for an AVL tree
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

int getheight(struct Node *n)//to get height of the tree
{
	if(n == NULL)
		return 0;
	return n->height;
}

struct Node *createNode(int key)//creating the nodes for an AVL tree
{
	struct Node *newnode;
	newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode -> key = key;
	newnode -> left = NULL;
	newnode -> right = NULL;
	newnode -> height = 1;
	return newnode;
}

int max(int a, int b)//get maximum element
{
	if(a > b)
		return a;
	else
		return b;
}

int getBalanceFactor(struct Node *n)
{
	if(n == NULL)
	{
		return 0;
	}
	return getheight(n->left)-getheight(n->right);
}

struct Node* rightRotate(struct Node* y)
{
	struct Node* x = y->left;
	struct Node* z = x -> right;
	
	x -> right = y;
	y -> left = z;

	x->height = max(getheight(x->right),getheight(x->left))+1;
	y->height = max(getheight(y->right),getheight(y->left))+1;

	return x;
}

struct Node* leftRotate(struct Node* x)
{
	struct Node* y = x ->right;
	struct Node* z = y -> left;
	
	y ->left = x;
	x->right=z;

	x->height = max(getheight(x->right),getheight(x->left))+1;
	y->height = max(getheight(y->right),getheight(y->left))+1;

	return y;
}

struct Node *insert(struct Node* node,int key)
{
	if(node == NULL)
		return createNode(key);
	
	if(key < node->key)
		node -> left = insert(node->left,key);
	else if(key > node -> key)
		node -> right = insert(node -> right,key);
	
	node -> height = 1+max(getheight(node->left),getheight(node->right));
	int bf = getBalanceFactor(node);

	//left left case

	if(bf > 1 && key < node ->left -> key)
	{
		return rightRotate(node);
	}

	//right right case

	if(bf < -1 && key > node -> right -> key)
	{
		return leftRotate(node);
	}

	//left right case

	if(bf > 1 && key > node -> left -> key)
	{
		node -> left = leftRotate(node -> left);
		return rightRotate(node);
	}

	//Right Left Case

	if(bf < -1 && key < node -> right -> key)
	{
		node -> right = rightRotate(node -> right);
		return leftRotate(node);
	}

	return node;
}

void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ",root -> key);
		preOrder(root -> left);
		preOrder(root -> right);
	}
}

int main()
{
	struct Node *root = NULL;
	root = insert(root,1);
	root = insert(root,2);
	root = insert(root,4);
	root = insert(root,5);
	root = insert(root,6);
	root = insert(root,3);
	preOrder(root);
	return 0;
}


