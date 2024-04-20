#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
void reverse_linked_list(struct node**);
void insert_at_end(struct node**,int);
int printlinkedlist(struct node*);
int main()
{
    struct node*head = NULL;
    insert_at_end(&head,45);
    insert_at_end(&head,34);
    insert_at_end(&head,24);
    insert_at_end(&head,14);
    insert_at_end(&head,4);
    int length = printlinkedlist(head);
    printf("\n length of linked list is  = %d ",length);
    reverse_linked_list(&head);
    printf("\nlinked list after reversing.");
	length = printlinkedlist(head);
	printf("\n length of linked list is  = %d ",length);

    


}
void reverse_linked_list(struct node**head1)
{
    if(*head1 == NULL)
    {
        printf("linked list is empty . ");
        exit(0);
    }
	
    struct node*temp;
    struct node*pre=NULL;
    struct node*front;
    temp = *head1;
    front = *head1;
    while(temp != NULL)
    {
        front = temp->link;
        temp->link = pre;
        pre = temp;
        temp = front;
    }
    if(temp == NULL)
    {
        *head1 = pre;
    }
}
// For input data into linked list
void insert_at_end(struct node**head1,int newdata)		//double is used because if linked list is empty then we store the address of specific  node in the head of main function
{
	if(*head1 == NULL)						// LIst is empty
	{
		struct node*temp;
		temp = (struct node*)malloc(sizeof(struct node));			// Creating specific  new node
		if(temp==NULL)
		{
			printf("\nMemory is not allocated.");
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
		printf("\nMemory is not allocated .");
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



// Printing the data and finding the length

int printlinkedlist(struct node*head)
{
	int count =0;
	if(head == NULL)
	{
		printf("\nThe linked list is empty.");
	}
	struct node *ptr=NULL;
	ptr  = head;
	printf("\nThe linked list elements =\n");
	while(ptr!=NULL)
	{
		count++; 
		printf("%d\t",ptr->data);
		ptr = ptr->link;
	}
	return count;
}
