#include<stdio.h>
#include<stdlib.h>

struct node//creating a node to single linked list
{
	int data;//data storedcin node
	struct node *next;//pointer pointing to the next address
};

struct node * create(int );//creating of node declaration
struct node* display(struct node*);

struct node* head = NULL;//node pointers
struct node* temp = NULL;
struct node* temp1 = NULL;

int main()
{
	int num1;
	int n;
	printf("Enter the number of nodes");
	scanf("%d", &n);
	for(int i = 0;i < n; i++)
	{
		printf("Enter data:");
		scanf("%d",&num1);
		head = create(num1);
	}
	display(head);

	return 0;
}

struct node* create(int num)//creating of a node to the linked list
{
	temp = (struct node*)malloc(sizeof(struct node));

	if(temp == NULL)
	{
		perror("error:");
		exit(1);
	}
	temp -> data = num;
	temp -> next = NULL;

	if(head == NULL)//checking whether the head is empty or not
	{
		head = temp;
	}
	
	else
	{
		temp1 = head;
		while(temp1 -> next != NULL)
		{
			temp1 = temp1 -> next ;
		}
		temp1 -> next = temp;
	}
	return head;
}

struct node* display(struct node* head)
{
	temp1 = head;
	if(head == NULL)
	{
		printf("The Linked list is empty");
	}
	printf("Nodes of single linked list are:");
	while(temp1 != NULL)
	{
		printf("%d -> ", temp1->data);
		temp1 = temp1->next;
	}
	return temp1;
	printf("\n");
}
