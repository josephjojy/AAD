#include<stdio.h>
#include<time.h>
int a[1000],b[1000],c[1000],A[1000],ac[1000];
int n,m,i,j,ch,m,temp,num;
FILE *f;
double t;
clock_t t1,t2;
void display()
{ 
  printf("\n\nBubble Sort:");
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
{t1=clock();
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
  }t2=clock();
}
void insertion()
{t1=clock();
  for(i=0;i<n;i++)
  {
    temp=b[i];
    for(j=i-1;(j>=0&&temp<b[j]);j--)
     b[j+1]=b[j];
    b[j+1]=temp;
  }t2=clock();
}
void selection()
{t1=clock();
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
  }t2=clock();
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
 f=fopen("ins.dat","a");
 fprintf(f,"\n%d\t",n);
 fclose(f);
 f=fopen("bub.dat","a");
 fprintf(f,"\n%d\t",n);
 fclose(f);
 f=fopen("sel.dat","a");
 fprintf(f,"\n%d\t",n);
 fclose(f);
 f=fopen("qk.dat","a");
 fprintf(f,"\n%d\t",n);
 fclose(f);
 for(ch=1;ch<4;ch++)
 { 
   if(ch==1)
     {
        printf("\nRandom\n");
	for(i=0;i<n;i++)
        {
          b[i]=c[i]=A[i]=a[i]=(rand()%n);
        }
     }
     if(ch==2)
     { 
        printf("\nAscending\n");
        for(i=0;i<n;i++)
        {
          ac[i]=b[i]=c[i]=A[i]=a[i]=a[i];
        }
     }
    if(ch==3)
     {
        printf("\nDescending\n");
        for(i=0;i<n;i++)
        {
          b[i]=c[i]=A[i]=a[i]=ac[n-i-1];
        }
     }
 
 
 insertion();
 printf("Insertion Sort=%f\n",((double) (t2 - t1)) / CLOCKS_PER_SEC);
 f=fopen("ins.dat","a");
 fprintf(f,"\t%f\t",((double) (t2 - t1)) / CLOCKS_PER_SEC);
 fclose(f);
 bubble();
 printf("Bubble Sort=%f\n",((double) (t2 - t1)) / CLOCKS_PER_SEC);
 f=fopen("bub.dat","a");
 fprintf(f,"\t%f\t",((double) (t2 - t1)) / CLOCKS_PER_SEC);
 fclose(f);
 selection();
 printf("Selection Sort=%f\n",((double) (t2 - t1)) / CLOCKS_PER_SEC);
 f=fopen("sel.dat","a");
 fprintf(f,"\t%f\t",((double) (t2 - t1)) / CLOCKS_PER_SEC);
 fclose(f);
 t1=clock();
 QuickSort(A,0,n-1);
 t2=clock();
 printf("Quick Sort=%f\n",((double) (t2 - t1)) / CLOCKS_PER_SEC);
 f=fopen("qk.dat","a");
 fprintf(f,"\t%f\t",((double) (t2 - t1)) / CLOCKS_PER_SEC);
 fclose(f);
 //display();
 

 

 
 
}
}
