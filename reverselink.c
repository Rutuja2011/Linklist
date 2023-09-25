
#include<stdio.h>
#include<stdlib.h>
#define NODEALLOC (struct node *)malloc(sizeof(struct node));
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
struct node *reverse(struct node *list)
{
   	struct node *p=NULL,*q=NULL,*r=NULL;
   	p=list;
   	while(p!=NULL)
   	{
   		r=q;
   		q=p;
   		p=p->next;
   		q->next=r;
   	}
   	list=q;
   	return list;
}
int main()
{
	struct node *list=NULL;
	list=create(list);
	disp(list);
	printf("\n revserse linklist:");
    list=reverse(list);
    disp(list);
}
