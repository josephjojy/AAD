#include<stdio.h>
int prim(int cost[][100],int n)
{
	int near[n],i,j,k,l,t[n][2];
	k=0;l=0;
    for(i=0;i<n;i++)
 	{
		if(cost[k][i]<cost[k][l]&&cost[k][i]!=999)
			l=i;
			
	}
	int mincost=cost[k][l];
	t[1][1]=l;
	t[1][2]=k;
	for(i=0;i<n;i++)
	{
		if(cost[i][l]<cost[i][k])
			near[i]=l;
		else
			near[i]=k;
	}
	near[k]=near[l]=0;
	for(i=0;i<n;i++)
		printf("\nnear[%d]=%d\n",i,near[i]);
	for(i=1;i<n;i++)
	{	
		int pos=0;
		for(j=0;j<n;j++)
		{printf("\nnear[%d]=%d\n",j,near[j]);
		printf("\ncost[%d][near[%d]]=%d\n",j,j,cost[j][near[j]]);
			if(near[j]!=0&&cost[j][near[j]]<cost[pos][near[pos]])
			{
				
				pos=j;
			}
		}
		j=pos;
		printf("\nJ=%d\nnear j=%d\n",j,near[j]);
		t[i][1]=j;
		t[i][2]=near[j];
		mincost=mincost+cost[j][near[j]];
		printf("\nMincost=%d\n",mincost);
		for(k=0;k<n;k++)
		{
			if(near[k]!=0&&cost[k][near[k]]>cost[k][j])
				near[k]=j;
		}
	}
	return mincost;
}
void main()
{
	int i,j,n;
	int cost[100][100];
	printf("Enter nummber of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Cost of %d-%d:",i,j);
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("\n\n%d\n\n",prim(cost,n));
}
