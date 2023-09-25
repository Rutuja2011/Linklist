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
		printf("enter value:");
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
   struct node *concate(struct node *list1,struct node *list2)
   {
   	struct node *temp;
   	for(temp=list1;temp->next!=NULL;temp=temp->next);
   	temp->next=list2;
   	return list1;
   }
   int main()
   {
   	struct node *list1=NULL,*list2=NULL;
   	list1=create(list1);
   	list2=create(list2);
   	list1=concate(list1,list2);
   	disp(list1);
}
