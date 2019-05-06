#include<stdio.h>

#define MAX 20
int E[MAX][MAX],belongs[MAX][MAX],t[MAX][2],cost[MAX][MAX],n,heap[MAX];





void heap()
{ int i,j,k=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			heap[k++]=E[i][j];
			
}


	void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        int temp=arr[i];
		arr[i]=arr[largest]; 
		arr[largest]=temp;
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 


int Find(int a)
{
	return(belongs[a]);
}

void UNION(int u, int v)
{
 int i;	
 for(i=0;i<n;i++)
	 if(belongs[i]==v)
		 belongs[i]=u;
}
int kruskal()
{
	heap();
	int i=0,mincost=0,j,k;
	for(j=0;j<n;j++)
		belongs[j]=j;
	while((i<n-1)&&())
	{
		heapify(heap,n*n,0);
		printf("\n\n%d\t\t%d\n\n\",heap[0],heap[48]);
		j=Find(u);
		k=Find(v);
		if(j!=k)
		{
			i=i+1;
			t[i][1]=u;
			t[i][2]=v;
			mincost=mincost+cost[u][v];
			UNION(u,v);
		}
	}
	return mincost;
}
void main()
{
	int i,j,total_cost;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	
	printf("\nEnter the adjacency matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&E[i][j]);
	
	total_cost=kruskal();
	printf("\nMinimum spanning tree :\n");
	
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=1;j<=2;j++)
			printf("%d\t",t[i][j]);
	}
	
	printf("\n\nMinimum cost of spanning tree=%d\n",total_cost);	
}
