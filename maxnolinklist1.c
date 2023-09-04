#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *create (struct node *list)
{
	int i,n; 
	struct node *newnode,*temp;
	printf("enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter vsalue:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(list==NULL)
		{
			list=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
		return list;
}
int findmax(struct node*list)
{
	struct node *temp;
	int max=list->data;
	for(temp=list;temp!=NULL;temp=temp->next)
	{
		if(temp->data>max)
		{
			max=temp->data;
		}
	}
	return max;
}

int main()
{
	struct node *list=NULL;
	list=create(list);
	printf("Maximum no=%d",findmax(list));
	
}




















