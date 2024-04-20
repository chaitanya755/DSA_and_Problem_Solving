// Inserting the node(data)in the linked list at the end
// In main function I used a very simple and basic way to insert element but in this program, our focus is only in the inser_at_end 
/* optionally , We add one more thing which is to return the position of new data in the linked list 
O(n) for inserting only
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
void printlinkedlist(struct node*head);
void insert_at_end(struct node**head1,int newdata)		//double is used because if linked list is empty then we store the address of specific  node in the head of main function
{
	if(*head1 == NULL)						// LIst is empty
	{
		struct node*temp;
		temp = (struct node*)malloc(sizeof(struct node));			// Creating specific  new node
		if(temp==NULL)
		{
			printf("Memory is not allocated.");
			exit(0);
		}
		temp->data = newdata;
		temp->link = NULL;
		*head1 = temp;
		
	}
	else{
	struct node*temp=NULL;					// For creating a new node
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Memory is not allocated .");
		exit(0);
	}
	temp->data = newdata;
	temp->link = NULL;
	struct node*ptr = NULL;					// For travershing means finding the last node in existing linked list
	ptr = *head1;
	while(ptr->link!=NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = temp;
	}
}
int main()
{
	struct node* head = NULL;				// This is the plur of the linked list
//	head = (struct node*)malloc(sizeof(struct node));		// specific  node
//	head->data = 45;
//	head->link = NULL;
//	struct node*current = NULL;
//	current = (struct node*)malloc(sizeof(struct node));			// Second node
//	current->data = 98;
//	current->link = NULL;
//	head->link = current;						// linking node to its previous node (specific )
//	current = (struct node*)malloc(sizeof(struct node));		// Third node
//	current->data = 3;
//	current->link = NULL;
//	head->link->link = current;						// linking node to its previous node(Second)
	//printf("%d\t%d\t%d",head->data,head->link->data,head->link->link->data);
//	current= (struct node*)malloc(sizeof(struct node));
//	current->data = 5;
//	current->link = NULL;
//	head->link->link->link = current;
	insert_at_end(&head,55);
	insert_at_end(&head,56);
	insert_at_end(&head,36);
	insert_at_end(&head,70);
	insert_at_end(&head,78);
	printlinkedlist(head);
	//printf("\n%d\t%d\t\t%d\t%d",head->data,head->link->data,head->link->link->data,head->link->link->link->data);
}

// Printing the data

void printlinkedlist(struct node*head)
{
	if(head == NULL)
	{
		printf("The linked list is empty.");
	}
	struct node *ptr=NULL;
	ptr  = head;
	printf("The linked list elements =\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr = ptr->link;
	}
}