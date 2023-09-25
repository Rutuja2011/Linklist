#include<stdio.h>
#include<stdlib.h>
#define NODEALLOC (NODE *)malloc(sizeof(NODE));
typedef struct node 
{
	int data;
	struct node *next;
}NODE;

NODE *create( NODE *list)
{
	NODE *newnode,*temp;
	int i, n;
	printf("enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=NODEALLOC;
		printf("enter value:");
		scanf("%d",&newnode->data);
		if(list==NULL)
		{
			list =temp=newnode;
			newnode->next=list;
		}
		else
		{
			temp->next=newnode;
			newnode->next=list;
			temp=newnode;
		}
	}
	return list;
}
void display(NODE *list)
{
	NODE *temp=list;
	do
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp!=list);
}
NODE *insertbeg(NODE *list,int num)
{
	NODE *temp,*newnode;
	newnode=NODEALLOC;
	newnode->data=num;
	for(temp=list;temp->next!=list;temp=temp->next);
	newnode->next=list;
	list=newnode;
	temp->next=list;
	return list;
}

NODE *insertend(NODE *list,int num)
{
	NODE *newnode,*temp;
	newnode=NODEALLOC;
	newnode->data=num;
	for(temp=list;temp->next!=list;temp=temp->next);
	temp->next=newnode;
	newnode->next=list;
	return list;
}

NODE *deletebeg(NODE *list)
{
	NODE *temp,*temp1;
	for(temp=list;temp->next!=list;temp=temp->next);
	temp1=list;
	list=list->next;
	temp->next=list;
	free(temp1);
	return list;
}
NODE *deleteend(NODE *list)
{
	NODE *temp,*temp1;
	for(temp=list;temp->next->next!=list;temp=temp->next);
	temp1=temp->next;
	temp->next=list;
	free(temp1);
	return list;
	
}
int main()
{
	int i,num,ch;
	NODE *list=NULL;
    do
    {
    	printf("\n1-create \n2-display \n3-insertbeg \n4-insertend \n5-deletebeg \n6-deleteend");
    	printf("\nenter choice");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:list=create(list);
    		        break;
    		case 2:display(list);
    		       break;
    		case 3:printf("enter number:");
    		       scanf("%d",&num);
    		       list=insertbeg(list,num);
    		       break;
    		case 4:printf("enter number:");
    		       scanf("%d",&num);
    		       list=insertend(list,num);
    		       break;
    		case 5:list=deletebeg(list);
    		       break;
    		case 6:list=deleteend(list);
    		       break;
    	
		}
	}while(ch<7);
}
