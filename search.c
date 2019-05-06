#include<stdio.h>
#include<time.h>

int i,first,last,mid,n,A[5000],search;
clock_t t1,t2,t3;

void Linear()
{
	for(i=0;i<n;i++)
    {
       if(A[i]==search)
         break;
    }
    if(i<n)
     printf("Element found at %d position\n",(i+1));
	else
		printf("Not Found\n");
}

void binary()
{
	first=0;last=n-1;
    while(first<=last)
    {
		mid=(first+last)/2;
		if(A[mid]==search)
        	break;
		else if(A[mid]<search)
			first=mid+1;
		else
			last=mid-1;
	}
    if(first<=last)
		printf("Element found at %d position\n",(mid+1));
	else
		printf("Not Found\n");
}

void main()
{
	int c=0;
	printf("Enter the size of array:");
    scanf("%d",&n);
	for(i=0;i<n;i++)
		A[i]=(i+1);
	while(c==0)
    {
	printf("Enter the element to be searched:");
	scanf("%d",&search);
    t1=clock();
    Linear();
    t2=clock();
    binary();
    t3=clock();
    printf("Linear= %f\n",((double) (t2 - t1)) / CLOCKS_PER_SEC);
	printf("Binary= %f\n",((double) (t3 - t2)) / CLOCKS_PER_SEC);
	scanf("%d",&c);
	}
}
