#include<stdio.h>
#include<stdlib.h>

struct node
{
	int item;
	struct node *left;
	struct node *right;
};

void inorderTraversal(struct node*);
void preorderTraversal(struct node*);
void postorderTraversal(struct node*);
struct node* create(int );
struct node* insertLeft(struct node*,int);
struct node* insertRight(struct node*, int);

int main()
{
	struct node* root = create(1);
	insertLeft(root, 4);
	insertRight(root,5);
	insertLeft(root->left,10);
	insertRight(root->left,20);
	insertLeft(root->right,25);
	insertRight(root->right,45);
	printf("Traversal of the inserted binary tree\n");
	printf("\nInorder Traversal\n");
	inorderTraversal(root);
	printf("\nPreorder Traversal\n");
	preorderTraversal(root);
	printf("\nPostorder Traversal\n");
	postorderTraversal(root);
	return 0;
}

void inorderTraversal(struct node* root)//For inorder traversal the root will be in middle
{
	if(root == NULL)
		return;
	inorderTraversal(root -> left);
	printf("%d ",root -> item);
	inorderTraversal(root -> right);
}

void preorderTraversal(struct node* root)
{
	if(root == NULL)
		return;
	printf("%d ",root -> item);
	preorderTraversal(root -> left);
	preorderTraversal(root -> right);
}

void postorderTraversal(struct node* root)
{
	if(root == NULL)
		return;
	postorderTraversal(root -> left);
	postorderTraversal(root -> right);
	printf("%d ", root -> item);
}

struct node* create(int value)
{
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode -> item = value;
	newnode -> left = NULL;
	newnode -> right = NULL;

	return newnode;
}

struct node* insertLeft(struct node* root, int value)
{
	root->left = create(value);
	return root ->left;
}

struct node* insertRight(struct node* root, int value)
{
	root -> right = create(value);
	return root -> right;
}

