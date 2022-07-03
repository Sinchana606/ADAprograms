#include <stdio.h>
int m[20][20];
int s[20][20];
int d[20],i,j,n;

void print_optimal(int i,int j)
{
if (i == j)
printf(" A%d ",i);
else
   {
      printf("( ");
      print_optimal(i, s[i][j]);
      print_optimal(s[i][j] + 1, j);
      printf(" )");
   }
}
void matrix_multiplication()
{
int q;
int k;
for(i=n;i>0;i--)
 {
   for(j=i;j<=n;j++)
    {
     if(i==j)
       m[i][j]=0;
     else
       {
        for(k=i;k<j;k++)
        {
         q=m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j];
         if(q<m[i][j])
          {
            m[i][j]=q;
            s[i][j]=k;
          }
         }
        }
      }
 }
}

int MatrixChainOrder(int d[], int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int min = 999;
    int count;
 
    for (k = i; k <j; k++)
    {
        count = MatrixChainOrder(d, i, k) +
                MatrixChainOrder(d, k+1, j) +
                d[i-1]*d[k]*d[j];
 
        if (count < min)
            min = count;
    }
 
    return min;
}

int main()
{
int k;
printf("Enter the no. Matrices: ");
scanf("%d",&n);
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
{
 m[i][i]=0;
 m[i][j]=999;
 s[i][j]=0;
}
printf("Enter the dimensions:(d vector) \n");
for(k=0;k<=n;k++)
{
 printf("d%d: ",k);
 scanf("%d",&d[k]);
}
matrix_multiplication();
printf("Matrix M table is\n");
for(i=1;i<=n;i++)
{
 for(j=1;j<=n;j++)
 {
  printf(" %d",m[i][j]);
 }
 printf("\n");
}

i=1,j=n;
printf("Multiplication Sequence : ");
print_optimal(i,j);
printf("\nMinimum number of multiplications is : %d ",
                          MatrixChainOrder(d, 1, n));
return 0;
}

output:
Enter the no. Matrices: 4
Enter the dimensions:(d vector) 
d0: 5
d1: 4
d2: 6
d3: 2
d4: 7
Matrix M table is
  0 120 88 158
  0  0  48 104
  0  0  0  84
  0  0  0  0
Multiplication Sequence : ( (  A1 (  A2  A3  ) ) A4  )
Minimum number of multiplications is : 158
