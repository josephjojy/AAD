#include<stdio.h>
 
void DFS(int);
int G[10][10],visited[10],n,a,result[10],k=0;    

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
			DFS(i);
			result[k]=(i+1);
			k++;
		}
	printf("\nResult:");
	for(i=0;i<n;i++)
		printf("%d ",result[n-i-1]);    
}
 
void DFS(int i)
{
    int j;
    visited[i]=1;
	
	for(j=0;j<n;j++)
      if(!visited[j]&&G[i][j]!=0)
        {    DFS(j);
			result[k]=(j+1);
			k++;}
}
