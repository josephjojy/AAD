#include<stdio.h>
#include<time.h>
int a[100],b[100],c[100],A[100];
int n,m,i,j,ch,m,temp,num;
double t;
clock_t t1,t2,t3,t4,t5;
void display()
{ 
  printf("\nBubble Sort:");
  for(int k=0;k<n;k++)
     printf(" %d ",a[k]);
   printf("\n");
  printf("\nInsertion Sort:");
  for(int k=0;k<n;k++)
     printf(" %d ",b[k]);
   printf("\n");
  printf("\nSelection Sort:");
  for(int k=0;k<n;k++)
     printf(" %d ",c[k]);
   printf("\n"); 
  printf("\nQuick Sort:");
  for(int k=0;k<n;k++)
     printf(" %d ",A[k]);
   printf("\n");
}
void bubble()
{
  for(i=0;i<n;i++)
  {
   for(j=0;j<n-i-1;j++)
   {
      if(a[j]>a[j+1])
      {
         temp=a[j];
         a[j]=a[j+1];
         a[j+1]=temp;
      }
   }
  }
}
void insertion()
{
  for(i=0;i<n;i++)
  {
    temp=b[i];
    for(j=i-1;(j>=0&&temp<b[j]);j--)
     b[j+1]=b[j];
    b[j+1]=temp;
  }
}
void selection()
{
  int min;
  for(i=0;i<n;i++)
  {
    min=i;
    for(j=i+1;j<n;j++)
    {
      if(c[min]>c[j])
        min=j;
    }
    temp=c[i];
    c[i]=c[min];
    c[min]=temp;
  }
}

int Partition(int A[100],int beg,int end)
{
 int loc=beg;
 while(1)
 {
   while(A[loc]<=A[end]&&loc!=end)
	end=end-1;
   if(loc==end)
 	return loc;
   int temp=A[loc];
   A[loc]=A[end];
   A[end]=temp;
   loc=end;
   while(A[loc]>=A[beg]&&loc!=beg)
	beg=beg+1;
   if(loc==beg)
	return loc;
   temp=A[loc];
   A[loc]=A[beg];
   A[beg]=temp;
   loc=beg;
 }
}
void QuickSort(int A[100],int beg,int end)
{
 if(beg<end)
 {
  int x=Partition(A,beg,end);
  QuickSort(A,beg,x-1);
  QuickSort(A,x+1,end);
 }
}

void main()
{
 printf("Enter Number of terms:");
 scanf("%d",&n);m=n;
 printf("Enter terms:\n");
 for(i=0;i<n;i++)
 {
   scanf("%d",&a[i]);
   b[i]=c[i]=A[i]=a[i];
 }
 t1=clock();
 bubble();
 t2=clock();
 insertion();
 t3=clock();
 selection();
 t4=clock();
 QuickSort(A,0,n-1);
 t5=clock();
 display();
 printf("Bubble Sort=%f\n",((double) (t2 - t1)) / CLOCKS_PER_SEC);
 printf("Insertion Sort=%f\n",((double) (t3 - t2)) / CLOCKS_PER_SEC);
 printf("Selection Sort=%f\n",((double) (t4 - t3)) / CLOCKS_PER_SEC);
 printf("Quick Sort=%f\n",((double) (t5 - t4)) / CLOCKS_PER_SEC);
 
 
}
