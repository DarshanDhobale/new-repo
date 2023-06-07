//this is a radix sort algorithm wrritten in c language


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 5



typedef struct node_tag
{
	char s1[size];
	struct node_tag* next;
}node;

typedef struct array_ll
{
	node * right;
}all;

void insert(char str[],all* ptr)
{
	node* p=(node*)malloc(sizeof(node));
	strcpy(p->s1,str);
	p->next=NULL;
	
	node* p1;
	
	if(ptr->right==NULL)
	{
		ptr->right=p;
	}
	else
	{
		p1=ptr->right;
		while(p1->next != NULL)
		{
			p1=p1->next;
		}
		p1->next=p;
	}
}


int main()
{
	int n,i,j,k;
	scanf("Enter the number of strings :");
	scanf("%td",&n);
	char str[n][size];
	for(i=0;i<n;i++)
	{
		scanf("%s",str[i]);
	}
	
	node* p;
	node* temp;
	all a1[26];
	for(i=0;i<26;i++)
	{
		a1[i].right=NULL;
	}
	
	for(j=strlen(str[0])-1;j>=0;j--)
	{
		for(i=0;i<n;i++)
		{
			insert(&str[i][0],&a1[str[i][j]-'a']);
		}
		
		
		i=0;
		for(k=0;k<26;k++)
		{
			if(a1[k].right!=NULL)
			{
				p=a1[k].right;
				do
				{
					strcpy(str[i],p->s1);
					i++;
					p=p->next;
				}while(p!=NULL);
			}
		}
		
		
		for(k=0;k<n;k++)
		{
			printf("%s ",str[k]);
		}
		printf("\n");
		
		
		for(k=0;k<26;k++)
		{
			if(a1[k].right!=NULL)
			{
				p=a1[k].right;
				a1[k].right=NULL;
				while(p!=NULL)
				{
					temp=p;
					p=p->next;
					free(temp);
				}
			}
		}	
		
	}
	return 0;
}
