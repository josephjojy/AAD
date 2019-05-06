#include<stdio.h>
#include<time.h>
#include<malloc.h>
struct node
{
  int data;
  struct node *next;
};
struct node *first=NULL;
struct node *current,*n;
int I,a,size;

void Remove(int i)
{
 current=first;
 for(a=0;a<i-2;a++)
    current=current->next;
 I=current->next->data;
 current->next=current->next->next;
 printf("List : ");
 current=first;
 for(;current!=NULL;current=current->next)
    printf(" %d ",current->data);
}
int next(int i)
{ current=first;
  for(a=0;a<i-1;a++)
    current=current->next;
  for(;current!=NULL;current=current->next)
  {
    if(current->data>I)
       return current->data;
  }
  printf("\nNOT FOUND\n");
}
void main()
{
 int c,i,j,d;
 double t;
 clock_t t1,t2;
 size=100;
 printf("Enter Elements:\n");
 for(a=0;a<size;a++)
 {
    d=rand();
    n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->next=NULL;
    if(first==NULL)
     { first=n;current=n;}
    else
     {current->next=n;
      current=current->next;}
 }
 i=50;
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

