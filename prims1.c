    #include<stdio.h>

    int u,v,n,i,j,ne=1;
    int visited[10]={0},min,mincost=0,cost[10][10];    
	int kruskal()
	{
    	visited[1]=1;
    	printf("\n");
    	while(ne<n) {
    		for (i=1,min=999;i<=n;i++)
    		   for (j=1;j<=n;j++)
    		    if(cost[i][j]<min)
    		     if(visited[i]!=0) {
    			min=cost[i][j];
    			u=i;
    			v=j;
    		}
    		if(visited[u]==0 || visited[v]==0) {
    			printf("\n Edge %d:(%d %d) cost:%d",ne++,u,v,min);
    			mincost+=min;
    			visited[v]=1;
    		}
    		cost[u][v]=cost[v][u]=999;
    	}
    	return mincost;
    
    }
	void main() {
    	
    	printf("\n Enter the number of nodes:");
    	scanf("%d",&n);
    	printf("\n Enter the adjacency matrix:\n");
    	for (i=1;i<=n;i++)
    	  for (j=1;j<=n;j++) {
    		scanf("%d",&cost[i][j]);
    		if(cost[i][j]==0)
    		    cost[i][j]=999;
    	}
		printf("\n Minimun cost=%d",kruskal());
	}
