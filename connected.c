#include<stdio.h>
 
void DFS(int);
int G[10][10],visited[10],n,a;    

void main()
{
    int i,j;
    printf("Enter number of vertices:");
   
	scanf("%d",&n);
 
	printf("\nEnter adjecency matrix of the graph:\n");
   
	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
   
    for(i=0;i<n;i++)
        visited[i]=0;
 
	
	for(i=0;i<n;i++)
		if(visited[i]==0)
		{
			a++;
			DFS(i);
		}
	printf("\n\nNo of connected graphs=%d\n",a);
	
    
}
 
void DFS(int i)
{
    int j;
    visited[i]=1;
	
	for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}
