#include <stdio.h>

int main()
{
  int a,b,p,q,i,j,k,sum=0;
  int one[10][10], two[10][10];
  int multiply[10][10];

  printf("Enter the number of rows and columns of first matrix\n");
  scanf("%d%d",&a,&b);
  printf("Enter the elements of first matrix\n");
  for (i= 0;i< a;i++)
    for (j= 0;j< b;j++)
      scanf("%d",&one[i][j]);

  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);
  if (b!= p)
    printf("The multiplication isn't possible.\n");
  else
  {
    printf("Enter elements of second matrix\n");

    for (i= 0;i< p;i++)
      for (j= 0;j< q;j++)
        scanf("%d", &two[i][j]);

    for (i= 0;i< a;i++) {
      for (j= 0;j< q;j++) {
        for (k = 0; k < p; k++) {
          sum = sum + one[i][k]*two[k][j];
        }

        multiply[i][j] = sum;
        sum = 0;
      }
    }

    printf("Product of the matrices:\n");

    for (i= 0;i< a;i++) {
      for (j= 0;j< q; j++)
        printf("%d\t", multiply[i][j]);

      printf("\n");
    }
  }

  return 0;
}
