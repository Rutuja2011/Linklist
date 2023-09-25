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
   void disp(struct node *list)
   {
   	 struct node *temp;
   	 for(temp=list;temp!=NULL;temp=temp->next)
   	 {
   	 	printf("%d\t",temp->data);
	 }
	 
   }
struct node *even(struct node *list)
{
	struct node *temp;
	for(temp=list;temp!=NULL;temp=temp->next)
	{
		if(temp->data%2==0)
		{
			printf("even number=%d",temp->data);
		}
	}
}
int main()
{
	struct node *list=NULL;
	list=create(list);
	disp(list);
	list=even(list);
}

