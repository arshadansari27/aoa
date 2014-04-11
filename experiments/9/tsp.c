#include<stdio.h>
#include<stdlib.h>

#define max 4
#define infinity 999

int tspdp(int c[][max],int tour[],int start,int n);

void main() {
    int n = 4;/* Number of cities. */
    int i,j; /*,c[max][max]; Loop counters. */
    int tour[max];/* Cost matrix. */
    int cost;/* Least cost. */
    int c[max][max] = {
        {0, 3, 2, 1},
        {1, 0, 4, 4},
        {3, 2, 0, 3},
        {1, 2, 1, 0}
    };

    printf("Travelling Salesman Problem Using Dynamic Programming\n");
    /*
    printf("\nEnter number of cities to traverse:");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++) {
            scanf("%d",&c[i][j]);
            if(c[i][j]==0)
                c[i][j]=999;
        }
    */
    for(i=0;i<n;i++)
        tour[i]=i;

    cost=tspdp(c,tour,0,n);

    printf("Minimum Cost: %d",cost);
    
    printf("\nTour:\n");

    for(i=0;i<n;i++)
        printf("%d - ",tour[i]+1);
    printf("1\n");

}

int tspdp(int c[][max],int tour[],int start,int n)
{
    int i,j,k;/* Loop counters. */
    int temp[max];/* Temporary during calculations. */
    int mintour[max];/* Minimal tour array. */
    int mincost;/* Minimal cost. */
    int cost;/* Current cost. */


    /* End of recursion condition. */
    if(start==n-2)
        return c[tour[n-2]][tour[n-1]]+c[tour[n-1]][0];

    /* Compute the tour starting from the current city. */
    mincost=infinity;
    for(i=start+1;i<n;i++)
    {
        for(j=0;j<n;j++)
            temp[j]=tour[j];


        /* Adjust positions. */
        temp[start+1]=tour[i];
        temp[i]=tour[start+1];

        /* Found a better cycle? (Recurrence derivable.) */
        if(c[tour[start]][tour[i]]+(cost=tspdp(c,temp,start+1,n))<mincost)
        {
            mincost=c[tour[start]][tour[i]]+cost;
            for(k=0;k<n;k++)
                mintour[k]=temp[k];
        }
    }

    /* Set the minimum-tour array. */
    for(i=0;i<n;i++)
        tour[i]=mintour[i];
    return mincost;
}
