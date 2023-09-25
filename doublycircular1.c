#include<stdio.h>
#include<stdlib.h>
#define NODEALLOC (struct node *)malloc(sizeof(struct node));
 struct node
{
	int data;
	struct node *next,*prev;
};
struct node *create(struct node *list)
{
	struct node *newnode,*temp;
	int i,n;
	printf("enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=NODEALLOC;
		printf("enter value:");
		scanf("%d",&newnode->data);
		if(list==NULL)
		{
			list=temp=newnode;
			newnode->next=list;
			list->prev=newnode;
			
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
			temp->next=list;
			list->prev=newnode;
		}
		
	}
	return list;
}
void display(struct node *list)
{
	struct node *temp=list;
	do
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp!=list);
}
struct node *insertbeg(struct node *list,int num)
{
	struct node *newnode,*temp;
	newnode=NODEALLOC;
	newnode->data=num;
	for(temp=list;temp->next!=list;temp=temp->next);
	newnode->next=list;
	list->prev=newnode;
	list=newnode;
	temp->next=list;
	list->prev=newnode;
}
struct node *insertmid(struct node *list,int num,int pos)
{
	int i;
	struct node *temp,*newnode;
	newnode=NODEALLOC;
	newnode->data=num;
	for(i=1,temp=list;i<pos-1 && temp->next!=list;i++,temp=temp=temp->next);
	newnode->next=temp->next;
	temp->next->prev=newnode;
	temp->next=newnode;
	newnode->prev=temp;
	return list; 
}
struct node *insertend(struct node *list,int num)
{
	struct node *newnode,*temp;
	newnode=NODEALLOC;
	newnode->data=num;
	for(temp=list;temp->next!=list;temp=temp->next);
	temp->next=newnode;
	newnode->prev=temp;
	newnode->next=list;
	list->prev=newnode;
	return list;
	
}
struct node *deletebeg(struct node *list)
{
	struct node *temp,*temp1;
	for(temp=list;temp->next!=list;temp=temp->next);
	temp1=list;
	list=list->next;
	list->prev=temp;
	temp->next=list;
	free(temp1);
	return list;
}
struct node *deletemid(struct node *list,int pos)
{
	int i;
	struct node *temp,*temp1;
	for(temp=list,i=1;i<pos-1&&temp->next!=list;i++,temp=temp->next);
	temp1=temp->next;
	temp->next=temp1->next;
	temp1->next->prev=temp;
	free(temp1);
	return list;
}
struct node *deleteend(struct node *list)
{
	struct node *temp,*temp1;
	for(temp=list;temp->next->next!=list;temp=temp->next);
	temp->next=list;
	list->prev=temp;
	free(temp1);
	return list;
	
}
int main()
{
	int num,ch,pos;
	struct node *list=NULL;
	do
	{
		printf("\n1-create \n2-display \n3-insertbeg \n4-insertmid \n5-insertend \n6-deltebeg \n7-deletemid \n7-deleteend");
		printf("\nenter choice:");
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
                   printf("enter position:");
                   scanf("%d",&pos);
                   list=insertmid(list,num,pos);
				   break;
		    case 5:printf("enter number:");
		           scanf("%d",&num);
		           list=insertend(list,num);
		           break;
		    case 6:list=deletebeg(list);
			       break;
		    case 7:printf("enter position:");
		           scanf("%d",&pos);
			       list=deletemid(list,pos);
			       break; 
			case 8:list=deleteend(list);
			       break;
				   
        }
    }while(ch<9);
}
