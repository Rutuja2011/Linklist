#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *prev,*next;
}NODE;

NODE  *create(NODE *list)
{
	int i,n;
	NODE *newnode,*temp;
	printf("enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		printf("enter number:");
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
			newnode->prev=temp;
			temp=newnode;
		}
	}
	return list;
}
void disp(NODE *list)
{
	NODE *temp;
	for(temp=list;temp!=NULL;temp=temp->next)
    {
    	printf("%d\t",temp->data);
	}
}
 NODE *insertbeg(NODE *list,int num)
 {
 	NODE *newnode;
 	newnode=(NODE *)malloc(sizeof(NODE*));
 	newnode->data=num;
 	newnode->next=list;
 	list->prev=newnode;
 	list=newnode;
 	return list;
 }
 
 int main()
 {
 	int i,n,num,ch;
 	struct node *list=NULL;
 	do
 	{
 	printf("\n-1create linklist\n2-display\n3-inertbeg");
 	printf("\nenter choice:");
 	scanf("%d",&ch);
 	switch(ch)
 	{
 		case 1:list=create(list);
 		       break;
 		case 2:disp(list);
 		       break;
 		case 3:printf("enter number:");
 		       scanf("%d",&num);
			   list=insertbeg(list,num);
				break;
	 }
   }while(ch<4);
 }
