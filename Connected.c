#include<stdio.h>
#include<stdlib.h>
#include"dataStr.h"
int queue[10]={0,0,0,0,0,0,0,0,0,0};
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
						newNode->next=NULL;
		//				printf("added %d %d",temp->value,newNode->value);				
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

void BfsTrav(arr *pointers,int a,int discovered[],int visited[])
{
		links *temp=pointers[a];
		if(!check(discovered,a))
			{
				add(discovered,a);
				add(queue,a);			
			}

		add(visited,a);
		extract(queue);
		while(temp!=NULL)
			{
				if(!check(discovered,temp->value))
				{
				add(queue,temp->value);
				counter=counter+(temp->weight);
				add(discovered,temp->value);
				}
				temp=temp->next;
			}
	if(queue[0]!=0)
{
	BfsTrav(pointers,queue[0],discovered,visited);
}		
}
void main()
{
	arr *pointers=calloc(sizeof(arr),10);
	insert(pointers,4,2,50);
	insert(pointers,2,4,20);
	insert(pointers,2,3,40);
	insert(pointers,3,2,40);
	insert(pointers,5,6,00);
	insert(pointers,6,5,00);


	int connectedComponents[10]={0,0,0,0,0,0,0,0,0,0};
	int ToBePrinted[10][10];
	int temp[10];
int discovered[10];
int visited[10];
int i;
int num=0;
FILE *fp=fopen("output.txt","w+");
for(i=1;i<=6;i++)
{
	int x=0;
	for(x=0;x<10;x++)
	{
	discovered[x]=0;
	visited[x]=0;
	queue[x]=0;
	temp[x]=0;
	}

	if(!check(connectedComponents,i))
{
	BfsTrav(pointers,i,discovered,visited);

	int j=0;
	while(visited[j]!=0)
	{
		add(connectedComponents,visited[j]);
		j++;	
	
	
	}
	//printf("%d",j);	
	add(temp,j);
	//printf("%d",temp[0]);
	int k=0;
	while(k<j)
	{
	//printf("%d",visited[k]);	
	add(temp,visited[k]);
	k++;
	}
	int l=0;
	for(l=0;l<=k;l++)
	{
		ToBePrinted[num][l]=temp[l];
		printf("%d",ToBePrinted[num][l]);	
	}
	
	num++;
	printf("\n");
	
	
}


}
	fprintf(fp,"%d\n",num);
int l;	
for(i=0;i<num;i++)
{	for(l=1;l<=ToBePrinted[i][0];l++)
	{
		fprintf(fp,"%d",ToBePrinted[i][l]);	
	}
			fprintf(fp,"\n");	
}


}



