#include<stdio.h>

#define MAX 20
int E[MAX][MAX],heap[MAX];
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



void main()
{
	int i,j,total_cost;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	
	printf("\nEnter the adjacency matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&E[i][j]);
	heap();
	heapify(heap,n*n,0);
	printf("\n\n%d\t\t%d\n\n\",heap[0],heap[48]);
}
	
