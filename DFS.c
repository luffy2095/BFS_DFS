#include<stdio.h>
#include<stdlib.h>
#include"dataStr.h"
int queue[10]={0,0,0,0,0,0,0,0,0,0};
int visited[10]={0,0,0,0,0,0,0,0,0,0};
int counter=0;
void insert(arr *pointer,int a, int b,int c)
{
	links *newNode=(links *)malloc(sizeof(links) * 1);	

if
	(pointer[a]==NULL)
	{
		pointer[a]=newNode;
		newNode->value=b;
		newNode->weight=c;
		newNode->par=0;
		newNode->next=NULL;
		//printf("added begin");
	}

else

	{
	links *temp=pointer[a];	
	while(1)
			{
				if(temp->next==NULL)
					{
						temp->next=newNode;
						newNode->value=b;
						newNode->weight=c;
						newNode->par=0;				
						newNode->next=NULL;
						//printf("added %d %d",temp->value,newNode->value);				
		break;					
					}
				temp=temp->next;				
			}	
	}

}
void extract(int a[])
{
	int i=0;
	for(i=0;i<9;)
	{
		a[i]=a[i+1];
		i++;
	}
	a[i]=0;
	

}
int check(int a[],int b)
{
	int i=0;
	for(i=0;i<10;i++)
		{
			if(a[i]==b){return 1;}		
		}
	if(i==10)
	return 0;
}

void add(int a[],int b)
{
	int i=0;
	while(a[i]!=0)
		{
			i++;		
		}
	a[i]=b;
	
}
void dfs_visit(arr *pointers,int s)
{
	links *temp=pointers[s];
	//links *prev=NULL;
	add(visited,s);
	while(temp!=NULL)
		{
			if(!check(visited,temp->value))
				{
					temp->par=s;					
					dfs_visit(pointers,temp->value);				
				}		
								
				temp=temp->next;	
		}
		return;
}
void dfs(arr *pointers, int s)
{
	int i;
	
			links *temp;
			add(visited,s);	
			//pointers[s]->par=NULL;
			temp=pointers[s];
			while(temp!=NULL)	
				{
					if(!check(visited,temp->value))
						{
							
					temp->par=s;
					dfs_visit(pointers,temp->value);						
						}
					temp=temp->next;				
				}	
}



void print_path(arr *pointers,int s,int v)
{
	if(s==v)
	{	printf("%d->",v);
		return;
	}	
		
	else{	
	links *temp;
	int i=1;int paren=0;
	for(i=1;i<=7;i++)
		{
			temp=pointers[i];
			while(temp!=NULL)
				{
					if(temp->value==v)
						{
							paren=temp->par;
							break;				
						}
					temp=temp->next;
				}
			if(paren!=0)
			break;		
		}
		if(paren==0)
		{
			printf("parent not found no path\n");
			return;		
		}
		
		else{print_path(pointers, s,paren);
			printf("%d->",v);			
			}
		
	}

		
}

void main()
{
	arr *pointers=calloc(sizeof(arr),10);
	insert(pointers,1,2,20);
	insert(pointers,1,4,30);
	insert(pointers,1,5,50);
	insert(pointers,2,1,20);
	insert(pointers,2,3,40);
	insert(pointers,5,1,50);
	insert(pointers,3,2,40);
	insert(pointers,4,1,30);
	insert(pointers,4,6,30);
	insert(pointers,6,4,30);	
	insert(pointers,2,7,30);
	insert(pointers,7,2,30);	
	int a=1;

	
	dfs(pointers,3);
	print_path(pointers,3,7);
	printf("\b\b");
//
//int i;
//for(i=0;i<10;i++)
//{
//printf("%d\n",visited[i]);
//}
//printf("\n\n\n%d",counter);	
}

