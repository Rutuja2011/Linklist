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
   struct node *insertbeg(struct node *list,int num)
   {
   	 struct node *newnode;
   	 newnode=(struct node*)malloc(sizeof(struct node));
   	 newnode->data=num;
   	 newnode->next=list;
   	 list=newnode;
   	 return list;
   }
   struct node *insertend(struct node *list,int num)
   {
   	 struct node *newnode,*temp;
   	 newnode=(struct node*)malloc(sizeof(struct node));
   	 newnode->data=num;
   	 newnode->next=NULL;
   	 for(temp=list;temp->next!=NULL;temp=temp->next);
   	 temp->next=newnode;
   	 return list;
   }
   struct node *insertmid(struct node *list ,int num,int pos)
   {
   	int i;
   	struct node *newnode,*temp;
   	newnode=(struct node *)malloc(sizeof(struct node));
   	newnode->data=num;
   	for(i=0,temp=list;i<pos-1 &&temp->next!=NULL;i++,temp=temp->next);
   	newnode->next=temp->next;
   	temp->next=newnode;
   	return list;  
}
 struct node *deletebeg(struct node*list)
 {
 	struct node *temp;
 	temp=list;
 	list=list->next;
 	free(temp);
 	return list;
 }
int main()
{
	int ch,num,pos;
	struct node*list=NULL;
	do
	{
		printf("\n1-create \n2-diplay \n3-insert beginning:");
		printf("\n4-insert end\n5-insert middle\n6-deletebeg");
		printf("\n enter choice:");
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
		    case 4:printf("enter number:");
		           scanf("%d",&num);
		           list=insertend(list,num);
		           break;
		    case 5:printf("enter number:");
		           scanf("%d",&num);
		           printf("enter positon:");
		           scanf("%d",&pos);
		           list=insertmid(list,num,pos);
		           break;
		    case 6:list=deletebeg(list);
		           break;
		}
	}while(ch<7);
	
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
	
	
	
	
	
	

