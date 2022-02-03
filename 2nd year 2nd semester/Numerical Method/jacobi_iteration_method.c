
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

void main()
{
    double a[10][10],x[10],y[10];
    /* ARRAY OF a[n][n] STORING COEFFICIENTS OF EQUATIONS */
    int i,j,n;
    printf("\n   JACOBI'S ITERATION METHOD TO SOLVE LINEAR EQUATIONS");

    printf("\n\nEnter the number of variables (max 10) = ");
    /* ENTER THE NUMBER OF VARIABLES IN THE EQUATION   */
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        /*  LOOP TO GET COEFFICIENTS a11,a12...,ann & so on  */
        for(j = 1; j <= n; j++)
        {
            printf("a%d%d = ",i,j);
            scanf("%lf",&a[i][j]);
        }
        printf("b%d = ",i);
        scanf("%lf",&a[i][j]);
        x[i] = y[i] = 0;
    }
    printf("\n\nThe results are as follows....\n\n");
    for(i = 1; i <= n; i++)
    {
        /*  LOOP TO CALCULATE VALUES OF x1,x2,...,xn etc  */
        for(j = 1; j <= n; j++)
        {
            if(i == j) continue;
            x[i] = x[i] - a[i][j]*y[j];
        }
        x[i] = x[i] + a[i][j];
        x[i] = x[i]/a[i][i];
    }
    for(i = 1; i <= n; i++)
    {
        /* LOOP TO PRINT VALUES OF x1,x2,...xn etc */
        y[i] = x[i];
        printf("x%d = %lf  ",i,x[i]);
        x[i] = 0;
    }
    return 0;
}
/*-------------------------------- END OF PROGRAM -----------------------*/
