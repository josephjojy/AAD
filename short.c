#include<stdio.h>

#define MAX 20

int cost[MAX][MAX],A[MAX][MAX];
int n,i,j,k;

int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}

void display()
{
	printf("\nShortest path:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
}

void path()
{
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			A[i][j]=cost[i][j];
    }
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				A[i][j]=min(A[i][j],(A[i][k]+A[k][j]));
		}
	}
}


void main()
{
	printf("Enter the no. of vertices:");
 	scanf("%d",&n);
    printf("Enter the cost matrix\n");
 	for(i=1;i<=n;i++)
 	{
 		 for(j=1;j<=n;j++)
  		{
   			scanf("%d",&cost[i][j]);
   			if(cost[i][j]==0&&i!=j)
    			cost[i][j]=999;
  		}
 	}
	path();
	display();
}
