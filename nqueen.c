#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
int board[20],count;
 

 
void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);
 
 
 for(i=1;i<=n;++i)
 {
 	printf("\n\n");
  for(j=1;j<=n;++j) 
  {
   if(board[i]==j)
    printf("\t1"); 
   else
    printf("\t0"); 
  }
 }
 printf("\n");
 
}


 int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  if(board[i]==column||abs(board[i]-column)==abs(i-row))
    return 0;
 }
 
 return 1; 
}
 

void nqueen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column; 
   if(row==n) 
    print(n); 
   else 
    nqueen(row+1,n);
  }
 }
}


int main()
{
 int n,i,j;
 printf("\n\nEnter number of Queens:");
 scanf("%d",&n);
 nqueen(1,n);
 return 0;
}
