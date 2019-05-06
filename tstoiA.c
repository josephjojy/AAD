#include<stdio.h>
#include<time.h>
int s[100],a,size,I;
void Remove(int i)
{
 I=s[i-1];
 for(a=0;a<size-1;a++)
  {
    if(a>=i-1)
     s[a]=s[a+1];
   }
 printf("Array : ");
 for(a=0;a<size-1;a++)
    printf(" %d ",s[a]);
 }
int next(int i)
{
  for(a=0;a<size-1;a++)
  {
    if(a>=i-1)
    {
     if(s[a]>I)
       return s[a];
    }
  }
  printf("\nNOT FOUND\n");
}
void main()
{
 int c,i,j;
 double t;
 clock_t t1,t2;
 printf("Enter Size of array:");
 scanf("%d",&size);
 printf("Enter Elements:\n");
 for(a=0;a<size;a++)
  scanf("%d",&s[a]);
 printf("Enter value of i:");
 scanf("%d",&i);
 if(i>size)
  printf("\nNot Possible\n");
 else
{
 t1=clock();
 Remove(i);
 j=next(i);printf("\nNext=%d\n",j);
 t2=clock();
 t = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
 printf("\ntime taken=%f\n",t);
 }
}

