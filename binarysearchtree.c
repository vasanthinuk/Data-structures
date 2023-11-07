#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;//globally initialized root pointer

struct node* createNode(int);//creating a node
void insert(int);
struct node* delete(struct node*, int);
int search(int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node* smallest_node(struct node*);
struct node* largest_node(struct node*);
int get_data();

int main()
{
	int ch;
	int data;
	struct node* res= NULL;
	printf("Implementation of binary search tree\n");
	while(1)
	{
		printf("1.Insert\n2.delete\n3.search\n4.Inorder\n5.Preorder\n6.Postorder\n7.smallest node\n8.largest node\n9.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : data = get_data();
				 insert(data);
				 break;
			case 2 : data = get_data();
				 delete(root,data);
				 break;
			case 3 : data = get_data();
				 if(search(data) == 1)
				 {
				 	printf("Data was found\n");
				 }
				 else
				 {
				 	printf("Data was not found\n");
				 }
				 break;
		 	case 4 : inorder(root);
				 break;
			case 5 : preorder(root);
				 break;
			case 6 : postorder(root);
				 break;
		 	case 7 : res = smallest_node(root);
				 if(res != NULL)
				 {
				 	printf("\nsmallest data:%d\n", res->data);
				 }
				 break;
			case 8 : res = largest_node(root);
				 if(res != NULL)
				 {
				 	printf("\nlargest data:%d\n", res->data);
				 }
				 break;
			case 9 : exit(1);
				 break;
			default :printf("Invalid choice\n");
		}
	}
	return 0;
}

struct node* createNode(int val)
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Memory for node can't be allocated\n");
	}
	ptr -> data = val;
	ptr -> left = NULL;
	ptr -> right = NULL;
	return ptr;
}

void insert(int val)
{
	struct node *ptr;
	ptr = createNode(val);
	if(ptr != NULL)
	{
		if(root == NULL)
		{
			root = ptr;
			printf("Node having %d was interested\n", val);
			return;
		}
	
		struct node* temp = root;
		struct node* prev = NULL;
		while(temp != NULL)//traverse through the BST to get position 
		{
			prev = temp;
			if(val > (temp -> data))
			{
				temp = temp -> right;
			}
			else
			{
				temp = temp -> left;
			}
		}	
	
		if(val > prev -> data)
		{
			prev -> right = ptr;
		}
		else
		{	
			prev -> left = ptr;
		}
		printf("\n Node having data %d inserted\n",val);
	}
}

struct node* delete(struct node* root, int data)
{
	if(root == NULL)
	{
		return root;
	}
	if(data < root -> data)
	{
		root -> left = delete(root->left,data);
	}
	else if(data > root -> data)
	{
		root -> right = delete(root->right, data);
	}
	else
	{
		if(root -> left == NULL)
		{
			struct node* temp = root -> right;
			free(root);
			return temp;
		}
		else if(root -> right == NULL)
		{
			struct node* temp = root -> left;
			free(root);
			return temp;
		}
		struct node* temp = smallest_node(root -> right);
		root -> data = temp -> data;
		root -> right = delete(root -> right, temp -> data);
	}
	return root;
}

int search(int val)//search for the node in binary search tree
{
	struct node* temp = root;
	while(temp != NULL)
	{
		if(val == temp -> data)
		{
			return 1;
		}
		else if(val > temp -> data)
		{
			temp = temp -> right;
		}
		else
		{
			temp = temp -> left;
		}
	}
	return 0;
}

struct node* smallest_node(struct node* root)//smallest node in BST
{
	struct node* curr = root;
	while(curr != NULL && curr -> left != NULL)
	{
		curr = curr -> left;
	}
	return curr;
}

struct node* largest_node(struct node* root)//maximum node in BST
{
	struct node* curr = root;
	while(curr != NULL && curr -> right != NULL)
	{
		curr = curr -> right;
	}
	return curr;
}


void preorder(struct node* root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d  ",root->data);
	preorder(root -> left);
	preorder(root -> right);
}

void inorder(struct node* root)
{
	if(root == NULL)
	{
		return;
	}
	inorder(root -> left);
	printf("%d  ", root -> data);
	inorder(root -> right);
}

void postorder(struct node* root)
{
	if(root == NULL)
	{
		return;
	}
	postorder(root -> left);
	postorder(root -> right);
	printf("%d  ", root -> data);
}

int get_data()
{
	int data;
	printf("Enter data:");
	scanf("%d", &data);
	return data;
}

