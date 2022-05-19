#include <stdio.h>
#include <math.h>
#define N    3     // size of matrix
#define N1   N+1
float matrix[N][N1]=
    {{-4,-2,6,-14},
  {-2,0,5,-7},
  {6,5,-14,2},
    };
void ShowMatrix(void)
{
  for (int i=0;i<N;i++)
  {
    for (int j=0;j<N;j++)
      printf("%+f*x%d",matrix[i][j],i+1);
    printf("=%f\n",matrix[i][N]);
  }
}
void main(void)
{
  // Variables declaration
  register char i,j,k;
  float s[N][N],x[N],y[N],d[N],sum;
  // Printing given matrix
  ShowMatrix();
  // Building matrixes S and D
  for (j=0;j<N;j++)
    for (i=0;i<=j;i++)
    {
      sum=matrix[i][j];
      for (k=0;k<i;k++)
        sum-=s[k][i]*d[k]*s[k][j];
      if (i==j)
      {
        d[i]=(sum>0?1:-1);
        s[i][j]=sqrt(fabs(sum));
      }
      else s[i][j]=sum/(d[i]*s[i][i]);
    }
