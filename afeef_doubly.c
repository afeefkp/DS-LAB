#include<stdio.h>
#include<stdlib.h>
struct node
	{
	int data;
	struct node *prev;
	struct node *next;
	};
struct node *newnode,*head,*temp,*preptr,*ptr;


	int x,i,n,op,d;
	void insertbeg();
	void insertpos();
	void insertend();
	void deletebeg();
	void deletepos();
	void deleteend();
	void display();

void main()
	{
		printf("\n 1.Insert at beginning\n 2.Insert at any posistion\n 3.Insert at end\n 4.Delete at beginning\n 5.Delete at any position\n 6.Delete at end\n 7.Exit\n");
		do{
		printf("\nEnter your option:");
		scanf("%d",&op);
			switch(op)
			{
				case 1:insertbeg();
				break;
				case 2:insertpos();
				break;
				case 3:insertend();
				break;
				case 4:deletebeg();
				break;
				case 5:deletepos();
				break;
				case 6:deleteend();
				break;
				default:printf("invalid option\n");
			}
		}while(op!=7);
	}
void display()
	{
		printf("Elements are:\n");
		ptr=head;
		while(ptr!=NULL)
		{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
		}
	}


void insertbeg()
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data to insert:");
		scanf("%d",&x);
		newnode->data=x;
		if(head==NULL)
		{
			newnode->prev=NULL;
			newnode->next=NULL;
			head=newnode;
		}
		else
		{
			newnode->prev=NULL;
			newnode->next=head;
			head->prev=newnode;
			head=newnode;
		}
		printf("Element successfully inserted\n");
		display();
	}

void insertpos()
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data to insert:");
		scanf("%d",&x);
		newnode->data=x;
		printf("Enter the data in the position in which new element is inserted:");
		scanf("%d",&n);
		ptr=head;
		while(ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
			if(ptr->data==n)
			{
				break;
			}
			}
				if(ptr->data==n)
			{
				temp->next=newnode;
				newnode->next=ptr;
				newnode->prev=temp;
				ptr->prev=newnode;
				printf("Element inserted successfully\n" );
				display();
			}
			else
			{
				printf("Element not found\n");
			}
	}

void insertend()
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data to insert:");
		scanf("%d",&x);
		newnode->data=x;
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->prev=ptr;
		newnode->next=NULL;
		printf("Element inserted successfully at end\n");
		display();
	}
void deletebeg()
	{
		if(head==NULL)
		{
			printf("Empty  Doubly linked list\n");
		}
		else
		{
			ptr=temp=head;
			ptr=ptr->next;
			ptr->prev=NULL;
			head=ptr;
			free(temp);
			printf("Element inserted successfully\n" );
			display();
		}
	}
void deletepos()
	{
		if(head==NULL)
		{
			printf("Empty  Doubly linked list\n");
		}
		else
		{
			ptr=head;
			printf("Enter the element to be deleted\n");
			scanf("%d",&d);
		while(ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
			if(ptr->data==d)
		{
			temp=ptr->next;
			break;
		}
		}
			if(ptr->data==d)
		{
			preptr->next=temp;
			temp->prev=preptr;
			free(ptr);
			printf("Element deleted successfully\n" );
			display();
		}
			else
		{
			printf("Element not found\n");
		}
		}
	}

void deleteend()
	{
		if(head==NULL)
		{
			printf("Empty  Doubly linked list\n");
		}
		else
		{
			ptr=head;
		while(ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
			preptr->next=NULL;
			free(ptr);
			printf("Element successfully deleted\n");
			display();
		}
	}







